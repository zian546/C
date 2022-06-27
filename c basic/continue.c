#include <stdio.h>

int main(void)
{
    int number = 0;
    while (number <= 100)
    {
        if (number % 10 == 0)
        {
            printf("\nfound %d!\n\n", number);
            number++;
            
        }

        printf("%d\n", number);
        number++;
       
    }
    
}