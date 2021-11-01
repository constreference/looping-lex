%{
    #include <stdio.h>
    long long T_KEYWORD = 0;
    long long T_SYMBOL = 0;
    long long T_IDENTIFIER = 0;
    long long T_DELIMITER = 0;
    long long T_LITERAL = 0;
    long long T_UNKNOWN = 0;
    long long T_OPERATOR = 0;
%}


keyword "int"|"char"|"double"|"float"|"void"|"long"|"short"|"static"|"volatile"|"register"|"break"|"continue"|"return"|"if"|"else"|"signed"|"unsigned"|"extern"|"if"|"else"|"goto"|"for"|"while"|"do"|"case"|"switch"|"union"|"struct"|"const"|"enum"
brackets "{"|"}"|"("|")"|"["|"]"
delimiters ","|";"
operators "+"|"-"|"*"|"/"|"%"|"^"|"&"|"|"|"<<"|">>"|"~"|"&&"|"||"|"?"|(("<"|">"|"="|"!")"="?)
digit [0-9]
letter [a-zA-Z_]





%%

{keyword}                                       { T_KEYWORD++; };
{brackets}                                      { T_SYMBOL++; };
{digit}+\.{digit}+(e("+"|"-")?{digit}+)?        { T_LITERAL++; };
{digit}+e(("+"|"-")?{digit}+)                   { T_LITERAL++; };
0[0-7]*                                         { T_LITERAL++; };
0x[{digit}a-fA-F]+                              { T_LITERAL++; };
{digit}+                                        { T_LITERAL++; };
\"[^\n]*\"                                      { T_LITERAL++; };
\'.\'                                           { T_LITERAL++; };
{operators}                                     { T_OPERATOR++; };
{letter}({letter}|{digit})*                     { T_IDENTIFIER++; };
[ \t\n]+                                        { T_DELIMITER++; };
.                                               { T_UNKNOWN++; };

%%


int yywrap() { return 1; }

int main() {
    yylex();
    printf ("No: of keywords %lld\n", T_KEYWORD);
    printf ("No: of literals %lld\n", T_LITERAL);
    printf ("No: of operators %lld\n", T_OPERATOR);
    printf ("No: of delimiters %lld\n", T_DELIMITER);
    printf ("No: of symbols %lld\n", T_SYMBOL);
    printf ("No: of unknown %lld\n", T_UNKNOWN);
    return 0;
}
