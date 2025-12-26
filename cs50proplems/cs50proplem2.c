#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    int number = 5;
    int guess = get_int("What is your guess ? \n");

    if (guess != number)
    {
        printf("Wrong Guess !\n");
    }
    else
    {
        printf("That is an amazing correct answer !!\n");
    }
}
