D                       [0-9]
L                       [a-zA-Z_]
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"

/* Ne g�re pas les commentaires. A rajouter */
/* Supprimer les lignes dont vous n'avez pas besoin. */

int yyerror(char *s){
         fprintf(stderr, "line %d: %s\n", yylineno, s);
        exit(1); // le prog s'arrete lors d'une erreur de syntaxe 
}

%}
%option yylineno
%%
<<EOF>>                 {printf("end of file\n"); exit(0);}
"/*"([^*]|(\*+[^*/]))*\**"*/" {printf("commentaire\n");}
"else"                  { printf("else ");return ELSE; }
"extern"                { printf("extern ");return EXTERN; }
"for"                   { printf("for ");return FOR; }
"if"                    { printf("if ");return IF; }
"int"                   { printf("int ");return INT; }
"return"                { printf("retour ");return RETURN; }
"sizeof"                { printf("sizeof ");return SIZEOF; }
"struct"                { printf("struct ");return STRUCT; }
"void"                  { printf("void ");return VOID; }
"while"                 { printf("while ");return WHILE; }

{L}({L}|{D})*           { printf("identifiant ");return IDENTIFIER; }
0{D}+{IS}?              { printf("constante0 ");return CONSTANT; }
{D}+{IS}?               { printf("constante ");return CONSTANT; }


"("                     {printf("( ");}
")"                     {printf(") ");}
"{"                     {printf("{ ");}
"}"                     {printf("} ");}
"="                     {printf("= ");}
"+"                     {printf("+ ");}
"-"                     {printf("- ");}
"*"                     {printf("* ");}
"<"                     {printf("< ");}
">"                     {printf("> ");}
"/"                     {printf("/ ");}
"&"                     {printf("& ");}
"++"                    {printf("++ ");}
"--"                    {printf("-- ");}
">>"                    {printf(">> ");}
"<<"                    {printf("<< ");}
";"                     {printf("; ");}
"->"                    {printf("-> "); return PTR_OP; }
"&&"                    {printf("&& "); return AND_OP; }
"||"                    {printf("|| "); return OR_OP; }
"<="                    {printf("<= "); return LE_OP; }
">="                    {printf(">= "); return GE_OP; }
"=="                    {printf("== "); return EQ_OP; }
"!="                    {printf("!= "); return NE_OP; }

[ \t\v\f]               {;}
[\n]                    {printf("\n");}
.                       {printf("lexical error"); /*yytext[0]);*/ }
%%


