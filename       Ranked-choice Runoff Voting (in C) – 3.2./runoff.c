#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}



// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    int m;

    for (int i = 0; i < candidate_count; i++)

    {
        m = strcmp(candidates[i].name, name);     // COMPARES THE NAME GIVEN BY THE VOTER AND THE CANDIDATES REAL NAMES

        if (m == 0)                                   // 
        {
            preferences[voter][rank] = i;  
            break;
        }

    }



    if (m == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    int cn;                                                                                     

    for (int v = 0; v < voter_count; v++)                           // VOTER BY VOTER          
    {
        for (int pr = 0 ; pr < candidate_count; pr++)                    //IN DECREASING PREFERENCE ORDER
        {
            cn =  preferences[v][pr];
            if (candidates[cn].eliminated == false)
            {
                candidates[cn].votes = candidates[cn].votes + 1;     // INCREASE THE TOP CANDIDATE'S VOTES 
                break;
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    string winner = "0";
  

    for (int c = 0; c < candidate_count; c++)                      // CHECK IF ONE CANDIDATE HAS MORE THAN THE HALF OF THE VOTES
    {
        if (candidates[c].votes > ((voter_count) / 2)  &&  candidates[c].eliminated == false)
        {
            winner = candidates[c].name;
        }
    }


    for (int j = 0; j < candidate_count; j++)
    {
        int m = strcmp(winner, candidates[j].name);          //IF A WINNER , PRINT HIS NAME
        if (m == 0)
        {
            printf("%s\n", candidates[j].name);
            return true;
        }
    }

    return false;

}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int mini = voter_count;                                 

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < mini && candidates[i].eliminated == false)
        {
            mini = candidates[i].votes;
        }
    }
    return mini;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int n = 0 ;                      // NUMBER OF CANDIDATES WITH THE MINIMUM VOTE TOTAL
    int ec = 0;               // NUMBER OF ELIMINATED CANDIDATES

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min &&  candidates[i].eliminated == false)
        {
            n++;
        }
        if (candidates[i].eliminated == true)
        {
            ec++;
        }
    }

    if (n == candidate_count - ec)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }

}
