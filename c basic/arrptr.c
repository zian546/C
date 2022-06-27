#include <stdio.h>

int main(void)
{
    int number[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    int *ptr[3];
    ptr[3] = number;
    printf("%d", *ptr);
}