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
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

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
    int m;

    for (int n = 0; n < candidate_count; n++)
    {
        m =  strcmp(candidates[n].name, name);     //THE INPUT MATCHES ONE THE NAME OF THE CANDIDATES IN THE ELECTION ?

        if (m == 0)                                // YES
        {
            candidates[n].votes++;         // UPDATE THE CANDIDATE'S VOTE TOTAL
            return true;
        }
    }
    return false;                                //  IF NOT    
}


// Print the winner (or winners) of the elections
void print_winner(void)
{
    int winvote = candidates[0].votes;


    for (int i = 0; i <  candidate_count ; i++)            // FIND THE BIGEST NUMBER OF VOTE
    {
        if (candidates[i].votes > winvote)                      
        {
            winvote = candidates[i].votes;
        }
    }


    for (j = 0; j < candidate_count; j++)                 // RESULTS: NAME(S) OF THE WINNER(S)
    {
        if (candidates[j].votes == winvote)
        {
            printf("%s\n", candidates[j].name);
        }
    }

}

