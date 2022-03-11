%{
#include<stdio.h>
#include<string.h>
int i = 0;
%}

%%
([a-zA-Z]*) {if(yytext[1]=='a'| yytext[1]== 'A') i++;} 

"\n" {printf("\nNo. of strings having a as second letter=%d\n", i); i=0;}
%%

int yywrap(void){}

int main()
{
	yylex();
    
	return 0;
}
