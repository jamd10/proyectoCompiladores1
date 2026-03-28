%{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "analysis.hpp"
#include "ast.hpp"

using namespace std;

int yylex();
void yyerror(const char* s);
extern int yylineno;

static std::vector<std::shared_ptr<ASTNode>>* createNodeList(std::shared_ptr<ASTNode> first) {
    auto* list = new std::vector<std::shared_ptr<ASTNode>>();
    if (first) {
        list->push_back(first);
    }
    return list;
}
%}

/* FIX 1: %code requires garantiza que estos includes aparezcan ANTES del %union
   en el .tab.h y .tab.c generados por Bison, resolviendo los errores de
   shared_ptr y vector "does not name a template type" */
%code requires {
    #include <memory>
    #include <vector>
    #include <string>
    #include "ast.hpp"
}

%union {
    long long ival;
    double fval;
    char* sval;
    std::shared_ptr<ASTNode>* node;
    std::vector<std::shared_ptr<ASTNode>>* nodelist;
}

/* typed terminals */
%token <sval> IDENTIFIER
%token <ival> INT_LIT
%token <fval> FLOAT_LIT
%token <sval> STRING_LIT
%token <sval> CHAR_LIT
%token TRUE FALSE

/* keywords */
%token FN LET IF ELSE WHILE FOR IN RETURN

/* primitive types */
%token TYPE_I32 TYPE_F64 TYPE_BOOL TYPE_CHAR TYPE_STR

/* operators and symbols */
%token ARROW ASSIGN COLON
%token PLUS MINUS MULT DIV
%token AND OR NOT
%token LT GT LE GE EQ NE
%token LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET
%token COMMA SEMICOLON

/* FIX 2: se eliminó 'param' de %type porque no existe como regla ni token,
   causaba el warning "symbol 'param' is used but not defined as a token" */
%type <node> program function return_opt parameter type block stmt let_stmt return_stmt if_stmt while_stmt for_stmt expr primary literal argument_item
%type <nodelist> function_list opt_params param_list stmt_list_opt stmt_list opt_args arg_list

%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MULT DIV
%right NOT
%right UMINUS

%start program

%%

program
    : function_list
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Program", *$1));
          g_astRoot = *$$;
          delete $1;
      }
    ;

function_list
    : function
      {
          $$ = createNodeList(*$1);
          delete $1;
      }
    | function_list function
      {
          $1->push_back(*$2);
          $$ = $1;
          delete $2;
      }
    ;

function
    : FN IDENTIFIER LPAREN opt_params RPAREN return_opt block
      {
          auto paramsNode = makeNode("Parameters", *$4);
          auto functionNode = makeNode(std::string("Function: ") + $2);
          appendChild(functionNode, paramsNode);
          appendChild(functionNode, *$6);
          appendChild(functionNode, *$7);
          $$ = new std::shared_ptr<ASTNode>(functionNode);

          free($2);
          delete $4;
          delete $6;
          delete $7;
      }
    ;

return_opt
    : ARROW type
      {
          auto node = makeNode("ReturnType");
          appendChild(node, *$2);
          $$ = new std::shared_ptr<ASTNode>(node);
          delete $2;
      }
    | /* empty */
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("ReturnType: void"));
      }
    ;

opt_params
    : param_list
      {
          $$ = $1;
      }
    | /* empty */
      {
          $$ = new std::vector<std::shared_ptr<ASTNode>>();
      }
    ;

param_list
    : parameter
      {
          $$ = createNodeList(*$1);
          delete $1;
      }
    | param_list COMMA parameter
      {
          $1->push_back(*$3);
          $$ = $1;
          delete $3;
      }
    ;

parameter
    : IDENTIFIER COLON type
      {
          auto node = makeNode(std::string("Parameter: ") + $1);
          appendChild(node, *$3);
          $$ = new std::shared_ptr<ASTNode>(node);

          free($1);
          delete $3;
      }
    ;

type
    : TYPE_I32
      { $$ = new std::shared_ptr<ASTNode>(makeNode("Type: i32")); }
    | TYPE_F64
      { $$ = new std::shared_ptr<ASTNode>(makeNode("Type: f64")); }
    | TYPE_BOOL
      { $$ = new std::shared_ptr<ASTNode>(makeNode("Type: bool")); }
    | TYPE_CHAR
      { $$ = new std::shared_ptr<ASTNode>(makeNode("Type: char")); }
    | TYPE_STR
      { $$ = new std::shared_ptr<ASTNode>(makeNode("Type: str")); }
    ;

block
    : LBRACE stmt_list_opt RBRACE
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Block", *$2));
          delete $2;
      }
    ;

stmt_list_opt
    : stmt_list
      {
          $$ = $1;
      }
    | /* empty */
      {
          $$ = new std::vector<std::shared_ptr<ASTNode>>();
      }
    ;

stmt_list
    : stmt
      {
          $$ = createNodeList(*$1);
          delete $1;
      }
    | stmt_list stmt
      {
          $1->push_back(*$2);
          $$ = $1;
          delete $2;
      }
    ;

stmt
    : let_stmt
      { $$ = $1; }
    | return_stmt
      { $$ = $1; }
    | if_stmt
      { $$ = $1; }
    | while_stmt
      { $$ = $1; }
    | for_stmt
      { $$ = $1; }
    | expr SEMICOLON
      {
          auto node = makeNode("ExpressionStatement");
          appendChild(node, *$1);
          $$ = new std::shared_ptr<ASTNode>(node);
          delete $1;
      }
    | block
      { $$ = $1; }
    ;

let_stmt
    : LET IDENTIFIER ASSIGN expr SEMICOLON
      {
          auto node = makeNode(std::string("Let: ") + $2);
          appendChild(node, *$4);
          $$ = new std::shared_ptr<ASTNode>(node);

          free($2);
          delete $4;
      }
    ;

return_stmt
    : RETURN expr SEMICOLON
      {
          auto node = makeNode("Return");
          appendChild(node, *$2);
          $$ = new std::shared_ptr<ASTNode>(node);
          delete $2;
      }
    | RETURN SEMICOLON
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Return"));
      }
    ;

if_stmt
    : IF expr block
      {
          auto node = makeNode("If");
          appendChild(node, makeNode("Condition", {*$2}));
          appendChild(node, *$3);
          $$ = new std::shared_ptr<ASTNode>(node);

          delete $2;
          delete $3;
      }
    | IF expr block ELSE block
      {
          auto node = makeNode("IfElse");
          appendChild(node, makeNode("Condition", {*$2}));
          appendChild(node, makeNode("Then", {*$3}));
          appendChild(node, makeNode("Else", {*$5}));
          $$ = new std::shared_ptr<ASTNode>(node);

          delete $2;
          delete $3;
          delete $5;
      }
    ;

while_stmt
    : WHILE expr block
      {
          auto node = makeNode("While");
          appendChild(node, makeNode("Condition", {*$2}));
          appendChild(node, *$3);
          $$ = new std::shared_ptr<ASTNode>(node);

          delete $2;
          delete $3;
      }
    ;

for_stmt
    : FOR IDENTIFIER IN expr block
      {
          auto node = makeNode(std::string("For: ") + $2);
          appendChild(node, makeNode("Iterable", {*$4}));
          appendChild(node, *$5);
          $$ = new std::shared_ptr<ASTNode>(node);

          free($2);
          delete $4;
          delete $5;
      }
    ;

expr
    : expr OR expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Op: ||", {*$1, *$3}));
          delete $1;
          delete $3;
      }
    | expr AND expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Op: &&", {*$1, *$3}));
          delete $1;
          delete $3;
      }
    | expr EQ expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Op: ==", {*$1, *$3}));
          delete $1;
          delete $3;
      }
    | expr NE expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Op: !=", {*$1, *$3}));
          delete $1;
          delete $3;
      }
    | expr LT expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Op: <", {*$1, *$3}));
          delete $1;
          delete $3;
      }
    | expr LE expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Op: <=", {*$1, *$3}));
          delete $1;
          delete $3;
      }
    | expr GT expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Op: >", {*$1, *$3}));
          delete $1;
          delete $3;
      }
    | expr GE expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Op: >=", {*$1, *$3}));
          delete $1;
          delete $3;
      }
    | expr PLUS expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Op: +", {*$1, *$3}));
          delete $1;
          delete $3;
      }
    | expr MINUS expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Op: -", {*$1, *$3}));
          delete $1;
          delete $3;
      }
    | expr MULT expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Op: *", {*$1, *$3}));
          delete $1;
          delete $3;
      }
    | expr DIV expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Op: /", {*$1, *$3}));
          delete $1;
          delete $3;
      }
    | NOT expr
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Unary: !", {*$2}));
          delete $2;
      }
    | MINUS expr %prec UMINUS
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Unary: -", {*$2}));
          delete $2;
      }
    | primary
      { $$ = $1; }
    ;

primary
    : IDENTIFIER
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode(std::string("Identifier: ") + $1));
          free($1);
      }
    | literal
      { $$ = $1; }
    | IDENTIFIER LPAREN opt_args RPAREN
      {
          auto callNode = makeNode(std::string("Call: ") + $1);
          appendChild(callNode, makeNode("Arguments", *$3));
          $$ = new std::shared_ptr<ASTNode>(callNode);

          free($1);
          delete $3;
      }
    | LPAREN expr RPAREN
      {
          $$ = $2;
      }
    ;

literal
    : INT_LIT
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Int: " + std::to_string($1)));
      }
    | FLOAT_LIT
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Float"));
      }
    | STRING_LIT
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode(std::string("String: ") + $1));
          free($1);
      }
    | CHAR_LIT
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode(std::string("Char: ") + $1));
          free($1);
      }
    | TRUE
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Bool: true"));
      }
    | FALSE
      {
          $$ = new std::shared_ptr<ASTNode>(makeNode("Bool: false"));
      }
    ;

opt_args
    : arg_list
      {
          $$ = $1;
      }
    | /* empty */
      {
          $$ = new std::vector<std::shared_ptr<ASTNode>>();
      }
    ;

arg_list
    : argument_item
      {
          $$ = createNodeList(*$1);
          delete $1;
      }
    | arg_list COMMA argument_item
      {
          $1->push_back(*$3);
          $$ = $1;
          delete $3;
      }
    ;

argument_item
    : expr
      { $$ = $1; }
    ;

%%

void yyerror(const char* s) {
    g_lastError = std::string("Syntax error at line ") + std::to_string(yylineno) + ": " + s;
}
