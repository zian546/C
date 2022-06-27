#include <stdio.h>
#include <stdlib.h>

int* sum(int* number_1, int* number_2)
{
    int *sumof = (int*)malloc(sizeof(int));   //reserve memory on heap so the data is safe
    *sumof = (*number_1) + (*number_2);
    return sumof;  //return the adress containing the value on heap

}
int main(void)
{
    int a;
    printf("please enter the first number = ");
    scanf("%d", &a);

    int b;
    printf("please enter the second number = ");
    scanf("%d", &b);

    int* c = sum(&a, &b);
    printf("the sum is %d\n", *c);

    //exit

    int exit;
    int* ptr = (int*)malloc(sizeof(exit));
    *ptr = exit;
    printf("press any key and enter to quit.");
    scanf("%d", ptr);
    free(ptr);
  
    

}