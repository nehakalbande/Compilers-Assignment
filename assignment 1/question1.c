#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <sys/stat.h>
#include<string.h>
#include <stdbool.h>
 
int dfa;
 
void start(char c)
{
    if(isalpha(c) || c == '_')
    dfa = 1;
    else
    dfa = -1;
}
 
 
void state1(char c)
{
    if(isalnum(c) || c==';' || c==',')
    dfa = 1;
    else
    dfa = -1;
}
 
bool DFA_for_ID(char *token)
{
    dfa = 0;
    int i, len = strlen(token);
    for(i=0; i<len ; i++)
    {
        if(dfa == 0)
        start(token[i]);
        else if(dfa == 1)
        state1(token[i]);
        else
        return 0;
    }
    if(dfa == 1)
    {
        return 1;
    }
    else
    return 0;
}
 
 
const char* filename = "input.c";
 
int main(int argc, char *argv[])
{
    FILE *in_file = fopen(filename, "r");
    if (!in_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
 
    struct stat sb;
    if (stat(filename, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
 
    char *x = malloc(sb.st_size);
    int count = 0;
    printf("The identifiers in the program are:\n");
    while (fscanf(in_file, "%[^\n ] ", x) != EOF)
    {
        int len = strlen(x);
        //printf("> %s\n", x);
        if(!strcmp(x, "if") || !strcmp(x, "else") || !strcmp(x, "while") || !strcmp(x, "do") ||    !strcmp(x, "break") || !strcmp(x, "continue") || !strcmp(x, "int")
   || !strcmp(x , "double") || !strcmp(x , "float") || !strcmp(x , "return") || !strcmp(x , "char") || !strcmp(x , "case") || !strcmp(x , "char")
   || !strcmp(x , "sizeof") || !strcmp(x , "long") || !strcmp(x , "short") || !strcmp(x , "typedef") || !strcmp(x , "switch") || !strcmp(x , "unsigned")
   || !strcmp(x , "void") || !strcmp(x , "static") || !strcmp(x , "struct") || !strcmp(x , "goto"))
        {
            continue;
        }
        else if(strchr(x, ']') != NULL)
        {
            char *e;
            int index;
            e = strchr(x, '[');
            char a[index+2];
            index = (int)(e - x);
            int i;
            for(i=0; i<index; i++)
            {
                a[i] = x[i];
               
            }
            a[i] = '\0';
            bool isIdentifier = DFA_for_ID(a);
            if(isIdentifier)
            {
                printf("%s\n", a);
                count++;
            }
        }
        else if(x[len-1] == ';' || x[len-1]==',' )
        {
            {
                bool isIdentifier = DFA_for_ID(x);
                if(isIdentifier)
                {
                    count++;
                    char *y = x;
                    for(int i = 0; i<len-1; i++)
                    {
                        printf("%c", y[i]);
                    }
                    printf("\n");
                }
            }
        }
        else{
            bool isIdentifier = DFA_for_ID(x);
            if(isIdentifier)
            {
                count += 1;
                printf("%s\n", x);
            }
        }
    }
    printf("\n");
    printf("The number of identifiers in the program are: %d", count);
 
    fclose(in_file);
    exit(EXIT_SUCCESS);
}
 
