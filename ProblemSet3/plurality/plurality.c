#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void BubbleSort(void);
void SwapCandidates(candidate *candidate1, candidate *candidate2);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }

    // Invalid voter
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Sort the candidates by vote count
    BubbleSort();

    int highestVoteCount = candidates[candidate_count - 1].votes;

    // Find all candidates that have the highest vote count (winners)
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == highestVoteCount)
        {
            // Print the winner
            printf("%s\n", candidates[i].name);
        }
    }

    // TODO
    return;
}

void BubbleSort(void)
{
    bool swappedValue = false;

    for (int i = 0; i < (candidate_count - 1); i++)
    {
        swappedValue = false;

        for (int j = 0; j < (candidate_count - i - 1); j++)
        {
            if (candidates[j].votes > candidates[j + 1].votes)
            {
                SwapCandidates(&candidates[j], &candidates[j + 1]);
                swappedValue = true;
            }
        }

        // If no swap was made, we can quit the sort.
        if (!swappedValue)
        {
            break;
        }
    }
}

// Swap the pointers of the candidates in the array
void SwapCandidates(candidate *candidate1, candidate *candidate2)
{
    candidate tempCandidate = *candidate1;

    *candidate1 = *candidate2;
    *candidate2 = tempCandidate;
}
