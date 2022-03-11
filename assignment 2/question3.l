%{
	#include<stdio.h>
	#include<string.h>
	int i=0;
%}

%%

([a-z0-9]*[\~\!\#\$\%\^\&\*\(\)\_\+\,\.\/\|\\\`\-\=\<\>\?\{\}\[\]\:\|\[\]\@"]+[a-z0-9]*) {i++;}
[a-zA-Z0-9]*
.
[\n] {printf("%d\n",i);i=0;}
%%

int yywrap(){};
int main()
{
	yylex();
	return 0;
}
