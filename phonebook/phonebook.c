#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"

int main(void)
{
string name = get_string ("what is you name ? ");
int age = get_int("whats your age ? ");
string number = get_string("whats your phone number ? ");

// you can use a string for the number if you want to add area code ..etc
// why chose a long ? you need it becasue there is a need for a high intiger
// string - preserves leading zeros


printf("your name is %s,Age is %i, Number is %s\n",name,age,number);

}


//for statements dont have to end with ;
// i=i+1 | is the same as i++ , you can close the loops with the pracets {}
// for (if this is true ) e.g for (int i =0; i < 10; i++) * The loop should go until 10
// there is a do / while loop  it basically it sets whats invalid {its mainly good to be used to get a certain input from the USER}
// e.g int n;
// do
//{
// n = get_int("n: "); [asking user for number of n ]
//}
// while (n <= 0);
// its always good to use int for digits because incase you want to
// increase them later on
// leave the space for the userto be able to enter data after the question mark
