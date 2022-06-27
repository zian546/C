#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// all the function that are used in this program
void StoreGradesEnd();      // function to construct linked list and store the grades(insert at the end)
void PrintGrades();         // function to print grades
void InputGrades();         // function to ask grades from the user and pass it onto the linked list constructor to be stored(call by value)
bool AskUser();             // function for getting user input
double Averages();          // function to calculate the average of the grades that are stored in the linked list
void PrintAverage();        // function to print the averages
void DeleteAll();           // function to delete the entire linked list
void TotalStudents();       // function to ask the user for the total students
void InsertSelect();        // function to insert a grades at a selected position
bool Invalid();             // function for an invalid input
void DeleteSelect();        // function to delete a certain grades within a certain position
void DeleteSelectSuccess(); // function to tell the user what position and what data that have been deleted

// block definition(grades and next block addresses)
typedef struct Nodes
{
    int grades;
    struct Nodes *next;
} Nodes;

int students_total;  // global variable used in this program indicating total students
bool stop;           // variable used to stop the main function
int new_student = 0; // a variable used indicating how many new students there are

Nodes *head; // the variable that stores the address of newly created block

int main(void) // driver function
{
    head = NULL; // this will be the end mark of the last block(if the linked list is constructed) and also be a mark of when the user hasn't submitted anything(when the linked list isn't yet constructed)

    while (stop != true) // this will evaluate whether the program is exited or not based on the stop variable
    {
        stop = AskUser();
    }
    return 0;
}

bool AskUser(void) // function for getting user input
{
    int to_do; // a variable that is used to store user choice

    printf("\nWELCOME\n\n");
    printf("1. View Your Student Grades\n");
    printf("2. Submit your students grades\n");
    printf("3. Average your student grades\n");
    printf("4. Delete the list\n");
    printf("5. Exit\n");
    printf("do : ");
    scanf("%d", &to_do); // scan for user choice and stores it in the to_do variable

    switch (to_do) // a switch statement that executes function based on user choice that have been stored in to_do variable
    {
    case 1:
        PrintGrades(); // print all the grades
        break;

    case 2:
        int case_2_choice;
        int select;

        printf("1. Insert a whole list of student grades\n");
        printf("2. Insert a grade at selected position\n");
        printf("do :");
        scanf("%d", &case_2_choice);

        if (case_2_choice == 1) // input the grades and stored it in a form of a linked list
        {
            select = 0;
            TotalStudents();
            InputGrades(new_student, select);
        }

        else if (case_2_choice == 2)
        {
            select = 1;
            InputGrades(new_student, select);
        }

        else
        {
            Invalid();
        }
        break;

    case 3:
        double average = Averages(); // this variable stores the average of the student grades

        // brancing based on user choice

        if (average == 0) // this will end the function if the user hadn't submitted anything
        {
            printf("There are no grades to average! submit your grades first!\n\n");
            break;
        }
        else if (average != 0) // this basically means the Averages function is working as intended
        {
            printf("The Average Grades of the students is : %lf \n\n", average); // print the average
            break;
        }
        break;

    case 4:
        int case_4_choice; // variable used to store the user choice

        printf("\nDelete the list : \n");
        printf("1. Delete the entire list\n");
        printf("2. Delete selected grades\n");
        printf("3. Back\n");
        printf("What do you wanna do : ");
        scanf("%d", &case_4_choice);

        // branching based on user choice

        if (case_4_choice == 1)
        {
            char confirmation;

            printf("Are you sure?(y/n) : ");
            scanf("%1s", &confirmation);

            if (confirmation == 'y')
            {
                DeleteAll(); // delete the entire list
            }
            else if (confirmation == 'n')
            {
                return false;
            }
            else
            {
                Invalid();
            }
            break;
        }

        if (case_4_choice == 2)
        {
            int position;

            PrintGrades();
            printf("Which grades do you wanna delete? : ");
            scanf("%d", &position);

            DeleteSelect(position);
            break;
        }

        if (case_4_choice == 3)
        {
            return false;

            break;
        }

        else
        {
            Invalid();
        }
        break;

    case 5:
        printf("\nprogram exited!\n\n"); // a case statement to exit the program
        return true;
        break;

    default:
        Invalid(); //  this will execute if the user input are over than the choices available
        break;
    }
    return false;
}

bool Invalid(void) // function for an invalid input
{
    printf("Invalid Input!");
    return false;
}

void TotalStudents(void) // function to ask the user for the total students
{
    new_student = 0;
    int temp = students_total;

    printf("enter the total number of student : "); // ask the user for total students
    scanf("%d", &new_student);

    students_total = new_student + temp;
}

void InputGrades(int students, int select) // function to ask grades from the user and pass it into the linked list constructor to be stored(call by value)
{
    int grades; // variable used to store the grades temporarily before passing it onto the linked list constructor
    int position;

    if (select == 1)
    {
        if (head != NULL) // this will print the grades after verifying there is actually something to print
        {
            PrintGrades(); // print the grades so user can see
        }

        printf("What position do you wanna put the grades : ");
        scanf("%d", &position);

        printf("enter your %d student grades : ", position);
        scanf("%d", &grades);
        InsertSelect(grades, position); // pass the grades that had been temporarily stored to the linked list constructor
        students_total++;               // +1 as your input means there is another student submitting their grades
    }

    else
    {
        for (int i = 0; i < students; i++ )// a loop to ask the user for the grades
        {
            printf("enter your %d student grades : ", i + 1);
            scanf("%d", &grades);
            StoreGradesEnd(grades); // pass the grades that had been temporarily stored to the linked list constructor
        }
    }
}

void StoreGradesEnd(int data) // function to construct linked list and store the grades(insert from the front/beginning)
{
    Nodes *block = (Nodes *)malloc(sizeof(Nodes)); // creates a new block in the list
    block->grades = data; // assign the value to the newly created block
    block->next = NULL; // initialize the next variable to null 

    Nodes *tracker = head; // tracker variable

    if (tracker == NULL) //exception handler which executes when the first block is created
    {
        head = block; // initialize the head variable
        return;
    }

    while (tracker->next != NULL) // loop to traverse the list and move to the last block on the list
    {
        tracker = tracker->next;
    }

    tracker->next = block; // assign the address of the current newly created block to the last block on the list
    return;
}

void PrintGrades(void) // function to print grades
{
    Nodes *tracker = head; // list tracker variable using the head as a reference
    int newlines = 0;

    if (tracker == NULL) // this will end the function if the user hadn't submitted anything (head variable hadn't stored any block address)
    {
        printf("\nNo grades to show!\n\n");
        return;
    }

    printf("\n");

    while (tracker != NULL) // printing loops will be executed if the tracker had stored a block address(linked list have been constructed)
    {

        if (newlines != 0 && newlines % 10 == 0)
        {
            printf("\n");
        }

        printf("%d. %d\n", newlines + 1, tracker->grades); // print the grades
        tracker = tracker->next;                           // move to the next block by changing the tracker value with the next block address stored in that particular block
        newlines++;
    }
    printf("\n");
    return;
}

double Averages(void) // function to calculate the average of the grades that are stored in the linked list
{
    Nodes *tracker = head;    // list tracker variable using the head as a reference
    double sumofgrades = 0.0; // variable used to store the total sum of the grades
    double storegrades = 0;   // a crucial variable used to stored summed grades to be used repeatedly in the while loops

    if (tracker == NULL) // this will end the function if the user hadn't submitted anything(works because the value of the head will always be NULL when we hasn't submitted anything, see the main function)
    {
        return 0;
    }

    while (tracker != NULL) // while loops to traverse the linked list and sum the value
    {
        sumofgrades = storegrades + tracker->grades; // sum the current linked list tracker address value with the previous summed grades
        storegrades = sumofgrades;                   // store the summed grades
        tracker = tracker->next;                     // move to the next block by changing the tracker value with the next block address stored in that particular block
    }

    double temp = (double)sumofgrades / students_total; // calculate the averages of the grades

    return temp; // return the average back to the AskUser function to be printed
}

void DeleteAll(void) // fucntion to delete the entire linked list
{
    Nodes *tracker = head; // tracker variable by using the head as a reference
    Nodes *tracker_2 = head;

    if (tracker == NULL) // this will end the function if the user hadn't submitted anything
    {
        printf("\nNothing to delete!\n");
        return;
    }

    while (tracker != NULL) // function to traverse the linked list from the front and delete the blocks
    {
        head = tracker->next;    // change the address that is stored in the head variable effectively erasing the current addres stored in the head variable
        tracker = tracker->next; // move the tracker variable to the next block
    }
    printf("List have been successfully deleted.\n");
}

void InsertSelect(int data, int position) // function to construct linked list and store the grades(insert from the n-th position)
{
    Nodes *block = (Nodes *)malloc(sizeof(Nodes)); // creates a new block in the list
    block->grades = data;                          // assign the value to the newly created block
    block->next = NULL;                            // always assign it to null so we can fill it later with addresses

    if (position == 1) // this puts the block in the beginning
    {
        block->next = head; // assign the previous block address to the current block that have been stored in the head variable to link the two blocks together
        head = block;       // store the current block address in the head variable
        return;
    }

    // below are the codes to link the block at the n-th position

    Nodes *tracker = head; // a tracker variable to traverse the linked list

    if (tracker == NULL)
    {
        printf("Position not found!\n");
        return;
    }

    for (int i = 0; i < position - 2; i++) // traverse the list to the n-1 position
    {
        if (tracker->next == NULL)
        {
            printf("Position not found!\n");
            return;
        }

        tracker = tracker->next;
    }

    block->next = tracker->next; // copy the address that have been stored in the n-1 position to the new block
    tracker->next = block;       // change the address at the n-1 position to the newly created block
}

void DeleteSelect(int position) // function to delete a certain grades within a certain position
{
    Nodes *temp1 = head;      // a tracker variable
    int position2 = position; // variable used to indicate position
    int data_to_delete;       // variable to indicate what data to delete

    if (position == 1) // an exception handler which executes if the position of the data that wants to be deleted is at position 1
    {
        head = temp1->next;
        return;
    }

    for (int i = 0; i < position - 2; i++) // loops to traverse the linked list till the n-1 position
    {
        temp1 = temp1->next;
        if (temp1 == NULL) // exception handler which execute if the given position doesn't exist
        {
            printf("Position not found!\n");
            return;
        }
    }

    data_to_delete = temp1->next->grades;
    Nodes *temp2 = temp1->next; // n-position node

    temp1->next = temp2->next; // adjust the pointer at n-1 position node to the addres stored at the n-position node effetively erasing the n position node

    DeleteSelectSuccess(&position2, &data_to_delete); // function to tell the user what position and what data that have been deleted
    return;
}

void DeleteSelectSuccess(int *position, int *data) // function to tell the user what position and what data that have been deleted
{
    printf("Deleted grades at position %d with value %d successfully!\n", *position, *data);
}