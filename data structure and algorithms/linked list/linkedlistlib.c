#include <stdio.h>
#include <stdlib.h>

typedef struct Nodes
{
    int data;
    struct Nodes *next;
} Nodes; // nodes type definition

Nodes *Head; // head variable used to keep track the first node in the list

void Beginning(int data) // function to create a neew node and insert the node in the beginning of the list
{
    Nodes *nodes = (Nodes *)malloc(sizeof(Nodes)); // create a new node
    nodes->data = data;                            // insert the value/data into the node
    nodes->next = Head;                            // assign the node address that have been stored in the head previously
    Head = nodes;                                  // assign and stores the newly created node address to the head variable
}

void Selected(int data, int position) //  function to create a neew node and insert the node in the selected position in the list
{
    Nodes *nodes = (Nodes *)malloc(sizeof(Nodes)); // create a new node
    nodes->data = data;                            // insert the value/data into the node
    nodes->next = NULL;                            // set the next block to null, because we want to fill it later and also to be a mark of the last node

    if (position == 1) // this is an exception handler and will executes if the given position to insert the data is at position 1
    {
        nodes->next = Head; // assign the next block in the newly created note with the address that have been stored in the head
        Head = nodes;       // assign the current newly created node addres to the head
        return;
    }

    Nodes *tracker = Head; //  create a tracker variable

    if (tracker == NULL) // this is an exception handler and will execute if the given position isn't on the list
    {
        return;
    }

    for (int i = 0; i < position - 2; i++) // basically travel to the n-1 position
    {
        tracker = tracker->next;
    }

    nodes->next = tracker->next; // copy the address stored at n-1 position and assign it to the newly created node
    tracker->next = nodes;       // assign the newly created node address to the n-1 node
}

void End(int data) //  funtion to create a new node and insert the node on the last place in the list
{
    Nodes *nodes = (Nodes *)malloc(sizeof(Nodes)); // create a new node
    nodes->data = data;                            // assign the data
    nodes->next = NULL;                            // set the next block in the node to null to be filled later and also to be the last node mark

    Nodes *tracker = Head; // create a tracker variable

    if (tracker == NULL) // this is an exception handler for node number 1 so that the program doesn't segfault
    {
        Head = nodes; // assign the newly created node address to the head
        return;
    }

    while (tracker != NULL) // basically travel to the last node on the list
    {
        if (tracker->next == NULL) // this will execute if the tracker variable is on the last node in the list because the last node always have the next block in that node to be null
        {
            tracker->next = nodes; // assign and store the newly created node to the last variable on the list
            return;
        }
        tracker = tracker->next; // move to the next node
    }
}

void DeleteAll() // function to delete the entire linked list
{
    Nodes *tracker = Head; // create a tracker variable

    if (tracker == NULL) // this is an exception handler if there is no nodes in the linked list
    {
        return;
    }

    while (tracker != NULL)
    {
        Head = tracker->next; // assign the head with the node address in the current tracker variable effectively erasing the previous node which the address is stored in the head variable
        free(tracker);        // free the memory where the deleted node reside before
        tracker = Head->next; // move to the next node
    }
}

void DeleteSelect(int position) // function to delete a selected node in the list
{
    Nodes *tracker = Head; // create a tracker variable

    for (int i = 0; i < position - 2; i++) // travel to the n-1 position
    {
        tracker = tracker->next;
    }

    Nodes *tracker_2 = tracker->next; // n-position node
    tracker->next = tracker_2->next;  // assign the n-1 with the address that the n position had stored effectively erasing the n node
    free(tracker_2);                  // actually delete and free the memory of the deleted nodes
}

void Print(void) // function to print the entire list
{
    Nodes *tracker = Head; // create a tracker variable
    int position = 1;      // variable used to indicate position

    while (tracker != NULL)
    {
        printf("%d. %d\n", position, tracker->data); // print the data stored in the node
        tracker = tracker->next;                     // move to the next node
        position++;
    }
}

void Reverse(void) // function to reverse the linked list
{
    Nodes *prev, *current, *next_node; // local variable used in this funciton
    current = Head;                    // assign the current variable to the head to get to the first node
    prev = NULL;                       // assign the prev variable as null to become a end mark of the list
    next_node = NULL;                  // initialize the next_node variable as null

    if (current == NULL) // exception handler that executes if the list is empty
    {
        return;
    }

    while (current != NULL) // loop to reverse the list
    {
        next_node = current->next; // assign the next_node variable with the address that have been stored in the current node to keep track of the nodes going forward in the list
        current->next = prev;      // assign the next block in the current node to the previous address that have been keep tracked with the prev variable
        prev = current;            //  move the prev variable to the current node
        current = next_node;       // move the current node to the next node in the list
    }

    Head = prev; // move the head to the new beginning of the list
}

int main(void)
{
    int limit;
    Head = NULL;

    scanf("%d", &limit);
    int data;

    for (int i = 0; i < limit; i++)
    {
        scanf("%d", &data);
        End(data);
    }

    Print();

    Reverse();

    printf("\n");

    Print();
}