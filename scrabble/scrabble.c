#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the first winner
    if (score1 > score2)
    {

        printf("Player 1 Wins !!\n");
    }
    // Print the second winner
    else if (score2 > score1)
    {
        printf("Player 2 Wins !!\n");
    }
    // Print the tie
    else
    {
        printf("Tie!\n");
    }c
}

int compute_score(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 65];
        }
        if (islower(word[i]))
        {
            score += POINTS[word[i] - 97];
        }
    }
    return score;
}
// Compute and return score for word
// uppercase = 65 to 90
// lowercase = 97 to 122
