#include <cs50.h>
#include <stdio.h>

// int i = 0 is forever
// if i added \n to the first printf it prints # in each line
// if i added a new printf("\n"); below it it sets them horizontally ###
// This will put the user in an endelss loop to aviod negative numbers
// int n;
// do
// {
//    n = get_int("Size: ")
// }
// while (n < 1)
// when adding voids let them be at the start of the code so that C can identify them

// || means or

int main(void)

{

    int height;
    int column;
    int row;
    int space;
    // you can add them in one line like int (int = height, row, column, space)
    do
    {
        height = get_int("Hight of Mario Pyramid ? ");
    }
    while (height > 8 || height < 1);

    // less that becasue the row number starts at 0

    for (row = 0; row < height; row++)

    {
        for (space = 0; space < height - row - 1; space++)

        // number of spaces increases (Height = row -1) so it would only make sence to increase spaces with each new line once the
        // nummber of spaces is less than the high and rows "<"
        {
            printf(" ");
        }
        for (column = 0; column <= row; column++)
        // less that becasue the row number starts at 0
        {
            printf("#");
        }
        printf("  ");

        for (column = 0; column <= row; column++)
        {
            printf("#");
        }

        printf("\n");
    }
}
