#include <stdio.h>

int main(void)
{
    int number_array[10];
    int *ptr = number_array;
    int a = 1;

    for (; ptr < &number_array[10]; ptr++)
    {
        *ptr = a;
        a = a * 2;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", number_array[i]);
    }

    int b = 0;
    ptr = number_array;

    for (; ptr < &number_array[10]; ptr++)
    {
        *ptr = b;
        b = 0;
    }

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", number_array[i]);
    }

}
