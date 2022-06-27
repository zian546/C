#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr;
    int number = 2;
    ptr = (int*)malloc(20 * sizeof(int));

    
    
    for (int i = 0; i < 20; i++)
    {
        ptr[i] = i * 2;
       
    }


    int newline = 0;
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", ptr[i]);
        if (newline == 4)
        {
            newline = 0;
            printf("\n");
        }
        newline++;
    }
    
    
}