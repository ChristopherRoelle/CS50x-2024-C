#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int CountLetters(string text);
int CountWords(string text);
int CountSentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    // Counts
    int letters = CountLetters(text);
    int words = CountWords(text);
    int sentences = CountSentences(text);

    // Averages per 100 'x'
    float averageLetters = ((float) letters / words) * 100.0;
    float averageSentences = ((float) sentences / words) * 100.0;

    // Coleman-Liau Index
    int gradeLevel = round(0.0588 * averageLetters - 0.296 * averageSentences - 15.8);

    // Print Grade Level
    if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gradeLevel);
    }
}

int CountLetters(string text)
{
    int letters = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int CountWords(string text)
{
    int words = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    //+1 for last word.
    return words + 1;
}

int CountSentences(string text)
{
    int sentences = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}
