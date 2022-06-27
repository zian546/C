#include <stdio.h>
#include <string.h>

void printstr(char *ptr)
{
    while (*ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");
    return;
}


int main(void)
{
    char words[256];
    printf("please enter a word : ");
    scanf("%s", words);
    printstr(words);
    return 0;
}