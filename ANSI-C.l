D                       [0-9]
L                       [a-zA-Z_]
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

%{
    #include "table_symb.h"
    #include "nodes.h"
    #include "y.tab.h"
    /* Ne g�re pas les commentaires. A rajouter */
    /* Supprimer les lignes dont vous n'avez pas besoin. */
%}
%option yylineno
%%
<<EOF>>                 { exit(0); }
"/*"([^*]|(\*+[^*/]))*\**"*/" {;}
"else"                  {return ELSE; }
"extern"                {return EXTERN; }
"for"                   {return FOR;}
"if"                    {return IF; }
"int"                   {return INT; }
"return"                {return RETURN; }
"sizeof"                {return SIZEOF; }
"struct"                {return STRUCT; }
"void"                  {return VOID; }
"while"                 {return WHILE; }

{L}({L}|{D})*           {yylval.nom = strdup(yytext); return IDENTIFIER; }
0{D}+{IS}?              {yylval.val = strdup(yytext); return CONSTANT; }
{D}+{IS}?               {yylval.val = strdup(yytext); return CONSTANT; }

"->"                    {return PTR_OP;}
"&&"                    {return AND_OP; }
"||"                    {return OR_OP; }
"<="                    {return LE_OP; }
">="                    {return GE_OP; }
"=="                    {return EQ_OP; }
"!="                    {return NE_OP; }

[ \t\v\f]               {;}
[\n]                    {;}
.                       {return yytext[0];}
%%


