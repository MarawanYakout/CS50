#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./ceasar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage : ./ceasar key\n");
            return 1;
        }
    }
        int key = atoi(argv[1]);

        string plaintext = get_string("plaintext: \n");
        printf("ciphertext: \n");

        for (int j = 0; j < strlen(plaintext); j++)
        {
            if (isupper(plaintext[j]))
            {
                printf("%c", (plaintext[j] - 65 + key) % 26 + 65);
            }
            else if (islower(plaintext[j]))
            {
                printf("%c", (plaintext[j] - 97 + key) % 26 + 97);
            }
            else
            {
                printf("%c", plaintext[j]);
            }
        }
        printf("\n");
        return 0;
    }

