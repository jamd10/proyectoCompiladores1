%{
#include "parser.tab.h"
#include "analysis.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#ifndef _WIN32
#define _strdup strdup
#endif
static void token(const char* type, const char* lexeme) {
    addToken(type, lexeme, yylineno);
}
%}
%option noyywrap
%option yylineno
%option nounput
%option noinput

DIGIT       [0-9]
LETTER      [a-zA-Z_]
ID          {LETTER}({LETTER}|{DIGIT})*
INT         {DIGIT}+
FLOAT       {DIGIT}+"."{DIGIT}+
STRING      \"([^\\\n]|(\\.))*\"
CHARVAL     \'([^\\\n]|(\\.))\'

%%

[ \t\r]+                ;
\n                      ;
"//".*                  ;
"/*"([^*]|\*+[^*/])*\*+"/"  ;

"fn"                    { token("FN",       yytext); return FN;       }
"let"                   { token("LET",      yytext); return LET;      }
"if"                    { token("IF",       yytext); return IF;       }
"else"                  { token("ELSE",     yytext); return ELSE;     }
"while"                 { token("WHILE",    yytext); return WHILE;    }
"for"                   { token("FOR",      yytext); return FOR;      }
"in"                    { token("IN",       yytext); return IN;       }
"return"                { token("RETURN",   yytext); return RETURN;   }
"true"                  { token("TRUE",     yytext); return TRUE;     }
"false"                 { token("FALSE",    yytext); return FALSE;    }
"i32"                   { token("TYPE_I32", yytext); return TYPE_I32; }
"f64"                   { token("TYPE_F64", yytext); return TYPE_F64; }
"bool"                  { token("TYPE_BOOL",yytext); return TYPE_BOOL;}
"char"                  { token("TYPE_CHAR",yytext); return TYPE_CHAR;}
"str"                   { token("TYPE_STR", yytext); return TYPE_STR; }

"->"                    { token("ARROW",     yytext); return ARROW;     }
":"                     { token("COLON",     yytext); return COLON;     }
"="                     { token("ASSIGN",    yytext); return ASSIGN;    }
"<="                    { token("LE",        yytext); return LE;        }
">="                    { token("GE",        yytext); return GE;        }
"=="                    { token("EQ",        yytext); return EQ;        }
"!="                    { token("NE",        yytext); return NE;        }
"<"                     { token("LT",        yytext); return LT;        }
">"                     { token("GT",        yytext); return GT;        }
"&&"                    { token("AND",       yytext); return AND;       }
"||"                    { token("OR",        yytext); return OR;        }
"!"                     { token("NOT",       yytext); return NOT;       }
"+"                     { token("PLUS",      yytext); return PLUS;      }
"-"                     { token("MINUS",     yytext); return MINUS;     }
"*"                     { token("MULT",      yytext); return MULT;      }
"/"                     { token("DIV",       yytext); return DIV;       }
"{"                     { token("LBRACE",    yytext); return LBRACE;    }
"}"                     { token("RBRACE",    yytext); return RBRACE;    }
"("                     { token("LPAREN",    yytext); return LPAREN;    }
")"                     { token("RPAREN",    yytext); return RPAREN;    }
"["                     { token("LBRACKET",  yytext); return LBRACKET;  }
"]"                     { token("RBRACKET",  yytext); return RBRACKET;  }
","                     { token("COMMA",     yytext); return COMMA;     }
";"                     { token("SEMICOLON", yytext); return SEMICOLON; }

{FLOAT}   {
    token("FLOAT_LIT", yytext);
    yylval.fval = atof(yytext);
    return FLOAT_LIT;
}

{INT}     {
    token("INT_LIT", yytext);
    yylval.ival = atoll(yytext);
    return INT_LIT;
}

{STRING}  {
    token("STRING_LIT", yytext);
    /* FIX: se almacena el valor sin las comillas delimitadoras */
    int len = strlen(yytext);
    char* s = (char*)malloc(len - 1); /* len-2 chars + '\0' */
    strncpy(s, yytext + 1, len - 2);
    s[len - 2] = '\0';
    yylval.sval = s;
    return STRING_LIT;
}

{CHARVAL} {
    token("CHAR_LIT", yytext);
    yylval.sval = _strdup(yytext);
    return CHAR_LIT;
}

{ID}      {
    token("IDENTIFIER", yytext);
    yylval.sval = _strdup(yytext);
    return IDENTIFIER;
}

.         { token("UNKNOWN", yytext); }

%%
