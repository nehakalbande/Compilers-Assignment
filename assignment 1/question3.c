#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define buff 1024

bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}


char* subString(char* str, int left, int right)
{
	int i;
	char* subStr = (char*)malloc(
				sizeof(char) * (right - left + 2));

	for (i = left; i <= right; i++)
		subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}



bool isConstant(char* str)
{
	if (
	 !strcmp(str, "int")
		|| !strcmp(str, "double") || !strcmp(str, "float")
		|| !strcmp(str, "char")|| !strcmp(str, "long")
		|| !strcmp(str, "short") || !strcmp(str, "unsigned")
		)
		return (true);
	return (false);
}

int parse(char* str)
{
	int left = 0, right = 0;
	int len = strlen(str);
    int count=0;

	char prev[25];
	strcpy(prev,"");

	while (right <= len && left <= right) {
		if (isDelimiter(str[right]) == false)
			right++;

		if (isDelimiter(str[right]) == true && left == right) {
			
			right++;
			left = right;
		} else if (isDelimiter(str[right]) == true && left != right
				|| (right == len && left != right)) {
			char* subStr = subString(str, left, right - 1);
            // printf("%s\n",subStr);
			if ((isConstant(subStr) == true) && (strcmp(prev, "const")==0))
            {

				printf("'%s' IS A Constant\n", subStr);
                count++;
            }
					// printf("%s %s %d\n",prev,subStr, strcmp(prev, "const"));
			strcpy(prev,subStr);
			left = right;
		}
	}
	return count;
}


int main()
{
    int constant_count = 0;
    char c[buff];
    FILE *fp;

    fp = fopen("input.c", "r");
    while ((fgets(c, buff, fp)) != NULL)
    {
        constant_count+=parse(c); 
    }
    printf("No of Constants are :%d\n", constant_count);
    fclose(fp);
}