#include <stdio.h>

int main(void)
{
    int const rows = 2;
    int const columns = 3;
    int multi_grades[2][3]= {
        
        {13,14,15},
        {56,78,90}
    };

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", multi_grades[i][j]);
        }
        printf("\n");
    }
}
