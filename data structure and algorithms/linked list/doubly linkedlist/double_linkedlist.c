#include <stdio.h>
#include <stdlib.h>

typedef struct Nodes // Nodes definition
{
    struct Nodes *prev;
    int data;
    struct Nodes *next;
} Nodes;

Nodes *Head = NULL;
Nodes *Tail = NULL;
int List_count = 0;

void ListCount() // function to count the total number of nodes in the list
{
    List_count++;
}

Nodes *GetNodes(int data) // function to create nodes and to store data
{
    Nodes *new_node = (Nodes *)malloc(sizeof(Nodes)); // create new nodes
    new_node->prev = NULL;                            // initialize the prev block to NULL
    new_node->data = data;                            // store data
    new_node->next = NULL;                            // initialize the next block to NULL

    ListCount();

    return new_node; // return the newly created node
}

int MidPosition(int total_list) // function to calculate the median of the list
{
    int median = total_list / 2;

    return median;
}

void InsertFront(int data) // function to insert new nodes on the front of the list
{
    Nodes *new_node = GetNodes(data); // create new nodes

    new_node->next = Head; // copy the stored address in the head node to the newly created node

    if (Head == NULL) // exception handler if the head is NULL indicating that the list is empty
    {
        Head = new_node; // store the newly created node address in the head node
        Tail = new_node; // store the newly created node address in the tail node

        return;
    }

    Head = new_node; // store the newly created node address in the head node, effectively putting the new node on the front of the list

    return;
}

void InsertEnd(int data) // function to insert new nodes on the end of the list
{
    Nodes *new_node = GetNodes(data); // create new nodes
    Nodes *temp = Head;

    if (temp == NULL) // exception handler if the head is NULL indicating that the list is empty
    {
        new_node->next = Head; // copy the stored address in the head node to the newly created node
        Head = new_node;       // store the newly created node address in the head node
        Tail = new_node;       // store the newly created node address in the tail node

        return;
    }

    while (temp->next != NULL) // travel the last node on the list
    {
        temp = temp->next;
    }

    temp->next = new_node; // set the next address on the last node in the list to be the next node
    new_node->prev = Tail; // copy the stored address in the tail node to the newly created node
    Tail = new_node;       // store the newly created node address in the tail node

    return;
}

void InsertSelect(int data, int position) // function to insert new nodes on selected position
{
    Nodes *new_node = GetNodes(data);     // create new nodes
    int median = MidPosition(List_count); // calculate the median

    Nodes *temp_next = Head; // head tracker variable
    Nodes *temp_prev = Tail; // tail tracker variable

    if (position == 1) // exception handler if the position selected is 1
    {
        new_node->next = Head; // copy the address stored in the head variable to the newly created nodes
        Head = new_node;       // store the new node address in the head variable

        return;
    }

    if (Head == NULL) // exception handler if the head is NULL indicating that the list is empty
    {
        return;
    }

    if (position < median) // this will execute if the position given is smaller than the median of the list
    {
        for (int i = 0; i < position - 2; i++) // move to the n-1 position from the beginning of the list
        {
            temp_next = temp_next->next;
        }

        new_node->next = temp_next->next; // copy the next address stored in the n-1 position of the list to the new node
        new_node->prev = temp_next;       // set the prev address on the new node to the current tracker address
        temp_next->next = new_node;       // adjust the next adress in the current n-1 position and set it to be the new node

        return;
    }

    if (position > median) //  this will execute if the position given is bigger than the median of the list
    {
        int total_list = List_count; // variable used to calculate movement to the n+1 position

        for (int i = 0; i < (total_list - 1) - position; i++) // move to n+1 position from the end of the list
        {
            temp_prev = temp_prev->prev;
        }

        new_node->prev = temp_prev->prev; // copy the prev address that had been stored in the n+1 position to the new node
        new_node->next = temp_prev;       // set the next address in the new node to be the n+1 position of the new node
        temp_prev->prev = new_node;       // adjust the prev address in the current  n+1 position and set it to be the new node

        return;
    }

    if (position == median)
    {
        for (int i = 0; i < position - 2; i++) // move to the n-1 position from the beginning of the list
        {
            temp_next = temp_next->next;
        }

        new_node->next = temp_next->next; // copy the next address stored in the n-1 position of the list to the new node
        new_node->prev = temp_next;       // set the prev address on the new node to the current tracker address
        temp_next->next = new_node;       // adjust the next adress in the current n-1 position and set it to be the new node

        return;
    }

    return;
}

void Print() // function to print the entire list from the front
{
    Nodes *temp = Head; // head tracker variable
    int position = 1;   // variable used to indicate position

    if (temp == NULL) // exception handler if the head is NULL indicating that the list is empty
    {
        return;
    }

    while (temp != NULL) // loop to print the data inside the list
    {
        printf("%d. %d \n", position, temp->data);
        temp = temp->next;
        position++;
    }

    return;
}

void PrintReverse() // function to print the entire list reversed/from the end
{
    Nodes *temp = Tail; // tail tracker variable
    int position = 1;   // variable used to indicate position

    if (temp == NULL) // exception handler if the head is NULL indicating that the list is empty
    {
        return;
    }

    while (temp != NULL)
    {
        printf("%d. %d \n", position, temp->data);
        temp = temp->prev;
        position++;
    }

    return;
}

void DeleteSelect(int position)
{
    Nodes *temp_head = Head;
    Nodes *temp_tail = Tail;
    int median = MidPosition(List_count); // calculate the median

    if (temp_head == NULL || temp_tail == NULL) // exception handler if the head is NULL indicating that the list is empty
    {
        return;
    }

    if (position == 1) // exception handler if the given position given is 1
    {
        Head = temp_head->next; // adjust the pointer memory address that had been stored in the head variable to the next node
        free(temp_head);        // free the memory of the deleted node

        return;
    }

    if (position < median)
    {
        for (int i = 0; i < position - 2; i++) // travel to n-1 position node from the beginning of the list
        {
            temp_head = temp_head->next;
        }

        Nodes *temp_delete = temp_head->next;    // n position node that will be deleted
        temp_head->next = temp_head->next->next; // adjust the n-1 next address to be the n+1 position address
        temp_head->next->prev = temp_head;       // adjust the n+1 prev address to be the n-1 position address
        free(temp_delete);                       // free the memory of the deleted node

        return;
    }

    if (position > median)
    {
        int total_list = List_count; // variable used to calculate movement sto the n+1 position

        for (int i = 0; i < (total_list - 1) - position; i++) // move to n+1 position from the end of the list
        {
            temp_tail = temp_tail->prev;
        }

        Nodes *temp_delete = temp_tail->prev;    // n position node that will be deleted
        temp_tail->prev = temp_tail->prev->prev; // adjust the n+1 prev address to be the n-1 position address
        temp_tail->prev->next = temp_tail;       // adjust the n-1 next address to be the n+1 position address
        free(temp_delete);                       // free the memory of the deleted node

        return;
    }

    if (position == median)
    {
        int total_list = List_count; // variable used to calculate movement to the n+1 position

        for (int i = 0; i < (total_list - 1) - position; i++) // move to n+1 position from the end of the list
        {
            temp_tail = temp_tail->prev;
        }

        Nodes *temp_delete = temp_tail->prev;    // n position node that will be deleted
        temp_tail->prev = temp_tail->prev->prev; // adjust the n+1 prev address to be the n-1 position address
        temp_tail->prev->next = temp_tail;       // adjust the n-1 next address to be the n+1 position address
        free(temp_delete);                       // free the memory of the deleted node

        return;
    }
}

void DeleteAll() // function to delete the entire list
{
    Nodes *temp_head = Head;        // head tracker variable
    Nodes *temp_delete = temp_head; // pointer variable used to free the memory of the deleted nodes

    if (Head == NULL) // exception handler if the head is NULL indicating that the list is empty
    {
        return;
    }

    while (temp_head == NULL) // loop to delete the list
    {
        Head = temp_head->next;      // adjust the address that had been stored in the head to be the node next to it, effectively blocking acces to the node address that had been stored before
        temp_head = temp_head->next; // move the temporary head tracker variable to the next node
        free(temp_delete);           // free the memory of the deleted node
        temp_delete = Head;          // assign
    }
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < 6; i++)
    {
        InsertEnd(arr[i]);
    }

    Print();

    printf("\n");

    DeleteSelect(5);

    Print();
}