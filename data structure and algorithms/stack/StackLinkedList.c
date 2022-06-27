#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Nodes
{
    int data;
    struct Nodes *next;
} Node; // node definition

Node *Top = NULL;

Node *NewNode(int data) // function to create new node
{
    Node *temp = (Node *)malloc(sizeof(Node)); // create new node in the heap
    temp->data = data;                         // store the data
    temp->next = NULL;                         // initialize the next node adress to null

    return temp;
}

void Insert(int data) // function to insert data at the front of the stack
{
    Node *temp = NewNode(data); // create new node
    temp->next = Top;           // store the address stored at the Topmost element to the newly created node
    Top = temp;                 // store the newly created node in the top variable making the newly created node to be the topmost element in the stack

    return;
}

void Pop(void) // function to remove the topmost data in the stack
{
    Node *temp_delete = Top; // variable used for deleteing the topmost node
    Top = Top->next;         // change the adress stored at the top variable to be the one next to it rendering the topmost element in the stack unaccessible

    free(temp_delete); // free the memory used in the topmost element in the stack

    return;
}

bool IsEmpty(void) // function to check if the stack are empty
{
    if (Top == NULL)
        return true;
    if (Top != NULL)
        return false;
}

void PrintTop()
{
    Node *temp = Top;

    printf("Top : %d\n", temp->data);
}

int main(int argc, char)
{
    Insert(6);
    Insert(7);
    PrintTop();
    Pop();
    PrintTop();
}