#import <cs50.h>
#import <ctype.h>
#import <stdio.h>
#import <string.h>

const int SCORES[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int CalculateScores(string word);

int main(void)
{

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int p1Score = CalculateScores(word1);
    int p2Score = CalculateScores(word2);

    if (p1Score > p2Score)
    {
        printf("Player 1 wins!\n");
    }
    else if (p1Score < p2Score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int CalculateScores(string word)
{
    int score = 0;

    for (int l = 0, length = strlen(word); l < length; l++)
    {
        score += SCORES[tolower(word[l]) - 'a'];
    }

    return score;
}
