#include <stdio.h>
#include <string.h>

char digits[] = "0123456789", sign[] = "+-";
char dot[] = ".", ex[] = "eE";
int dfa[11][5];


void makeDFA()
{
    dfa[0][0] = 1;

    dfa[1][0] = 1;
    dfa[1][2] = 3;
    dfa[1][3] = 2;
    dfa[1][4] = 6;

    dfa[3][0] = 4;

    dfa[4][0] = 4;
    dfa[4][3] = 5;
    dfa[4][4] = 6;

    dfa[6][0] = 8;
    dfa[6][1] = 7;

    dfa[7][0] = 8;

    dfa[8][0] = 8;
    dfa[8][3] = 9;
}

void buildDFA()
{

    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 5; j++)
            dfa[i][j] = 10;

    
    makeDFA();

   

}
    int checkD(char k)
    {

        for (int j = 0; j < strlen(digits); j++)

            if (k == digits[j])
            {
                return 1;
            }
        return 0;
    }
    int checkSign(char k)
    {

        for (int j = 0; j < strlen(sign); j++)

            if (k == sign[j])
            {
                return 1;
            }
        return 0;
    }
    int checkDot(char k)
    {

        for (int j = 0; j < strlen(dot); j++)

            if (k == dot[j])
            {
                return 1;
            }
        return 0;
    }
    int checkEx(char k)
    {

        for (int j = 0; j < strlen(ex); j++)

            if (k == ex[j])
            {
                return 1;
            }
        return 0;
    }

    void checkDFA(char s[])
    {
        buildDFA();

        int currentstate = 0;

        for (int i = 0; i < strlen(s); i++)
        {
            if (checkD(s[i]))
                currentstate = dfa[currentstate][0];
            else if (checkSign(s[i]))
                currentstate = dfa[currentstate][1];
            else if (checkDot(s[i]))
                currentstate = dfa[currentstate][2];
            else if (checkEx(s[i]))
                currentstate = dfa[currentstate][4];
            else
                currentstate = dfa[currentstate][3];
        }

        if (currentstate == 1 || currentstate == 4 || currentstate == 8)
        {
            printf("%s is an Unsigned integer", s);
        }
        else
        {
            printf("%s is not an unsigned integer", s);
        }
    }

    int main()
    {
        char S[] = "1729";
        checkDFA(S);

        return 0;
    }
