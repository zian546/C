#include <stdio.h>
#include <stdbool.h>

#define MAX 101
int Stack[MAX]; // array used for the stack
int Top = -1; // variable used to indicate the topmost element in the stack while also function to indicate the stack size and also a variable used to acces the stack(print,delete,etc.)

void Push(int data) // function to push element to the stack
{
    if (Top == MAX-1) // exception handler if the stack is full
    {
        printf("Error : The stack is full!\n");
        return;
    }

    Top++; // increment the top variable indicating there is a new element to push
    Stack[Top] = data; // push the element to the stack

    return;
}

void Pop() // function to delete the topmost element in the stack
{
    printf("Top element : %d\n", Stack[Top]);
    printf("Deleting....\n");

    Top--; // decrement the top variable to delete the topmost element by making it unaccesable

    printf("Succesfully deleted!\n");
    
    return;
}

bool IsEmpty() // function to check if the stack is empty
{
    if (Top < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Print() // function to print the entire stack element for testing purposes
{
    if (Top == -1)
    {
        printf("Error : no element to print!");
        return;
    }

    printf("Stack : ");
    for(int i = 0; i <= Top; i++)
    {
       printf("%d ", Stack[i]); 
    }

    printf("\n");
}

void PrintTop() // function to print the topmost element in the stack 
{
    printf("Top : %d\n", Stack[Top]);
}

int main(int argc, char)
{
    Push(3);
    Print();
    Push(2);
    Print();
    Push(1);
    Print();
    PrintTop();
    Pop();
    PrintTop();
    Pop();
}