#include <stdio.h>
#include <stdbool.h>
// variable used in all the function

bool view_grades_confirmation = false;
int to_do;

void continous_user_input()
{

    printf("please choose what to do :\n ");
    printf("1. enter student grades(max 30)\n");
    printf("2. view your student grades\n");
    printf("3. exit program\n");
    scanf("%d", &to_do);

    while (to_do > 4 || to_do < 0)
    {
        printf("please choose what to do :\n ");
        printf("1. enter student grades\n");
        printf("2. view your student grades\n");
        printf("3. exit program\n");
        getchar();
        scanf("%d", &to_do);
    }

    return;
}

void input_grades(int *grades, int *finish)
{

    view_grades_confirmation = true;
    int student_count = 1;
    int inject_value = 0;

    for (; grades < finish; grades++)
    {
        printf("student number %d grades is : ", student_count);
        getchar();
        scanf("%d", &grades[inject_value]);
        student_count++;
        inject_value++;
    }

    return;
}

void view_grades(int *grades, int *finish)
{
    if (view_grades_confirmation)
    {
        int value_view = 0;
        int student_count = 1;

        printf("student\t");
        printf("grades\n");
        for (; grades < finish; grades++)
        {
            printf("%d.\t", student_count);
            printf("%d\n", *grades + value_view);
            student_count++;
            value_view++;
        }
    }
    else
    {
        printf("you haven't submitted your students grades yet!\n\n");
    }

    return;
}

int do_stuff()
{
    int grades[30];
    int *start = grades;
    int *finish = &grades[30];

    continous_user_input();

    if (to_do == 1)
    {
        input_grades(start, finish);
        continous_user_input();
        return  1;
    }

    if (to_do == 2)

    {
        view_grades(start, finish);
        continous_user_input();
        return 1;
    }

    if (to_do == 3)

    {
        printf("program exited!\n");
        return 0;
    }
}

int main()
{
    int track;
    do
    {
        track  = do_stuff();
    } while (track != 0);
    
    return 0;
}
