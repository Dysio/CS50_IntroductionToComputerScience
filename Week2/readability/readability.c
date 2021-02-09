#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Function declaration */
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Getting user input as string
    string text = get_string("Text: ");
    // calling functions which count letters, words and sentences in text
    int num_of_letters = count_letters(text);
    int num_of_words = count_words(text);
    int num_of_sentences = count_sentences(text);

    // Calculating L and S parameters for index type casting of int numbers into float (float) num_of_letters
    float L = (float) num_of_letters / num_of_words * 100;
    float S = (float) num_of_sentences / num_of_words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

/* Functions counts number of letters in text */
int count_letters(string text)
{
    int num_of_let = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            num_of_let++;
        }
    }

    return num_of_let;
}

/* Functions counts number of words in text */
int count_words(string text)
{
    int num_of_words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            num_of_words++;
        }
    }
    num_of_words++;

    return num_of_words;
}

/* Functions counts number of sentences in text */
int count_sentences(string text)
{
    int num_of_sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            num_of_sentences++;
        }
    }

    return num_of_sentences;
}
