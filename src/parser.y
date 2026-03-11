%{
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int yylex();
void yyerror(const char *s);
extern int yylineno;
%}

%union {
    long long ival;
    char* sval;
}

/* TOKENS */
%token <sval> IDENTIFIER
%token <ival> INT_LIT

%token FN LET IF ELSE WHILE RETURN
%token TYPE_I32 TYPE_F64 TYPE_BOOL TYPE_CHAR TYPE_STR

%token PLUS MINUS MULT DIV
%token AND OR NOT
%token ASSIGN
%token COLON
%token ARROW

%token LT GT LE GE EQ NE

%token LBRACE RBRACE LPAREN RPAREN
%token COMMA SEMICOLON

/* PRECEDENCIA */
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

program:
    function_list
    ;

function_list:
      function
    | function_list function
    ;

function:
    FN IDENTIFIER LPAREN parameters_opt RPAREN return_opt block
    ;

return_opt:
      ARROW type
    | /* empty */
    ;

parameters_opt:
      parameters
    | /* empty */
    ;

parameters:
      parameter
    | parameters COMMA parameter
    ;

parameter:
    IDENTIFIER COLON type
    ;

type:
      TYPE_I32
    | TYPE_F64
    | TYPE_BOOL
    | TYPE_CHAR
    | TYPE_STR
    ;

block:
    LBRACE stmt_list_opt RBRACE
    ;

stmt_list_opt:
      stmt_list
    | /* empty */
    ;

stmt_list:
      stmt
    | stmt_list stmt
    ;

stmt:
      LET IDENTIFIER ASSIGN expr SEMICOLON
    | RETURN expr SEMICOLON
    | RETURN SEMICOLON
    | IF expr block
    | IF expr block ELSE block
    | expr SEMICOLON
    ;

expr:
      expr PLUS expr
    | expr MINUS expr
    | expr MULT expr
    | expr DIV expr
    | expr LT expr
    | expr GT expr
    | expr LE expr
    | expr GE expr
    | expr EQ expr
    | expr NE expr
    | expr AND expr
    | expr OR expr
    | NOT expr
    | MINUS expr %prec UMINUS
    | primary
    ;

primary:
      IDENTIFIER
    | INT_LIT
    | IDENTIFIER LPAREN arg_opt RPAREN
    | LPAREN expr RPAREN
    ;

arg_opt:
      arg_list
    | /* empty */
    ;

arg_list:
      expr
    | arg_list COMMA expr
    ;

%%

void yyerror(const char *s) {
    cerr << "Syntax error at line " << yylineno << endl;
}