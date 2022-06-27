#include <stdio.h>

int main(void)
{
    int number = 25;
    int *number_pointer = &number;

    printf("%d\n", *number_pointer);


    *number_pointer = 50;

    printf("%d\n", *number_pointer);

    for (int i = *number_pointer; i < 60; i++)
    {
        printf("%d\n", i);
    }

}
