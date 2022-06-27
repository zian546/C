#include <stdio.h>

void increment_10(int *ptr)
{
    for(int i = 0;i < 10;i++)
    {
        *ptr = *ptr + 1;

    }
    return;
}
int main(void)
{
    int number = 0;
    increment_10(&number);
    printf("%d\n",number);
    return 0;



}