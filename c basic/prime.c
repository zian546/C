#include <stdio.h>
#include <stdbool.h>

int main(prime_checker)
{
    //get user input for number
    int number = 10;
    
    if(prime_checker == true)
    {
        printf("%d", number);
    }
    



}

bool prime_checker(number)
{
    for(number; number > 1; number--)
    {
        int check = number % 2;
        int check_2 = number % 3;

        if(check != 0 && check_2 != 0)
        {
            return true;
        }       
    }
}