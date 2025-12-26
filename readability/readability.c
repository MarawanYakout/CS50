#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");
    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text) + 1;
    int sentences = count_sentences(text);
    // Compute the Coleman-Liau index
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letter_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}

// or we use if ((text[i]> 65 && text[i] < 90) || (text [i] > 97 && text [i] < 122))
// Return the number of letters in text
// uppercase = 65 to 90
// lowercase = 97 to 122

int count_words(string text)
{
    int word_count = 0;
    for (int i = 0; i < strlen(text); i++)
    if (text[i] == ' ')
    {
        word_count++;
    }
    return word_count;
}

// Return the number of words in text by counting the number of spaces beacuse you cant possibly
// count the words
int count_sentences(string text)
{
    int sentence_count = 0;
    for (int i = 0; i < strlen(text); i++)
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence_count++;
        }
    return sentence_count;
}
