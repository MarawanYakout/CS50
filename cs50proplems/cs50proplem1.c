#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int value(int x);

int main (void)
{

    int x = 1;
    int y = value(x);
    printf("x is %i, y is %i\n", x, y);
}
int value(int x)
{
    x++;
    return x;
}
