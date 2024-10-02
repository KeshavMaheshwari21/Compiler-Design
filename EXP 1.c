// Write a Program in C to identify whether given string is keyword or not
#include<stdio.h>
#include<string.h>

int main()
{
    char input[20];
    int i;
    int j = 0;
    
    printf("Enter the String: ");
    scanf("%s", input);

    const char keywords[12][10] = {"auto","break","do","while","case","char","const","continue","default","double","else","extern"};
    
    for(i = 0; i < 12; i++)
    {
        if(strcmp(keywords[i], input) == 0)
        {
            j = 1;
            break;
        }
    }
    
    if(j == 0)
    {
        printf("Not a Keyword!\n");
    }
    else
    {
        printf("Keyword!\n");
    }
    
    return 0;
}
