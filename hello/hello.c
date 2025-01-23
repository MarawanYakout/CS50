#include <stdio.h>
#include <cs50.h>

int main(void)
{
// Prompt for name
    string name = get_string("What is your name? ");
    printf("Hello, %s\n", name);
}
