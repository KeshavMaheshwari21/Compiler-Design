#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char ch;
    char str[100];
    int status = 0, i = 0, count = 0;

    fp = fopen("abc.txt", "r");
    if (fp == NULL)
    {
        printf("Error in opening the file\n");
        return 1;
    }

    printf("C Keywords in the File are : \n");

    while (fgets(str, sizeof(str), fp) != NULL)
    {
        i = 0;
        status = 0;

        while (str[i] != '\0' && str[i] != '\n')
        {
            ch = str[i];
            if (ch == 'i' && status == 0)
            {
                status = 1;
            }
            else if (ch == 'n' && status == 1)
            {
                status = 2;
            }
            else if (ch == 't' && status == 2)
            {
                status = 3;
                printf("int\n");
                count++;
            }
            else if (ch == ' ' || ch == '\t' || ch == '\n' || ch == ',')
            {
                status = 0;
            }
            else if ((ch == 'f') && (status == 0))
            {
                status = 4;
            }
            else if ((ch == 'o') && (status == 4))
            {
                status = 5;
            }
            else if ((ch == 'r') && (status == 5))
            {
                status = 6;
                printf("for\n");
                count++;
            }
            else if ((ch == 'l') && (status == 4))
            {
                status = 7;
            }
            else if ((ch == 'o') && (status == 7))
            {
                status = 8;
            }
            else if ((ch == 'a') && (status == 8))
            {
                status = 9;
            }
            else if ((ch == 't') && (status == 9))
            {
                status = 10;
                printf("float\n");
                count++;
            }
            else if ((ch == 'f') && (status == 1))
            {
                status = 11;
                printf("if\n");
                count++;
            }
            else if ((ch == 'e') && (status == 0))
            {
                status = 12;
            }
            else if ((ch == 'l') && (status == 12))
            {
                status = 13;
            }
            else if ((ch == 's') && (status == 13))
            {
                status = 14;
            }
            else if ((ch == 'e') && (status == 14))
            {
                status = 15;
                printf("else\n");
                count++;
            }
            else if ((ch == 'd') && (status == 0))
            {
                status = 16;
            }
            else if ((ch == 'o') && (status == 16))
            {
                status = 17;
                printf("do\n");
                count++;
            }
            else
            {
                status = 0;
            }
            i++;
        }
    }

    fclose(fp);
    printf("Total Keywords: %d\n", count);
    return 0;
}
