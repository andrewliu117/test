%%
"+"	{ printf("plus\n"); }
"-" { printf("minus\n"); }
"*" { printf("times\n"); }
"/" { printf("divide\n"); }
"|" { printf("abs\n"); }
[0-9]+ { printf("number %s\n", yytext); }
\n	{ printf("newline\n"); }
[ \t]	{ }
.	{ printf("unkown character %s\n", yytext); }
%%

int main(int argc, char **argv) {
	yylex();
}
