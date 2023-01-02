// Return grade level of a string of text based on the Coleman-Liau Index
// Uses helper functions from CS50 library

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get a piece of text as user input
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the average letters and sentences per 100 words
    float L = (float)letters / (float)words * 100;
    float S = (float)sentences / (float)words * 100;

    // Calculate Coleman-Liau Index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print grade level of text depending on index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
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
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        text[i] = tolower(text[i]);

        // Calculate the position of each letter in the index of the alphabet
        int position = text[i] - 'a';

        // Increase number of letters if character is a letter
        if (position <= 25 && position >= 0)
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int spaces = 0;
    int words = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Count number of spaces while looping through the text
        if (text[i] == ' ')
        {
            spaces++;
        }
    }

    // Calculate number of words by adding 1 to number of sentences
    words = spaces + 1;

    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Find number of punctuation marks in the text
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    // Return number of sentences
    return sentences;
}
