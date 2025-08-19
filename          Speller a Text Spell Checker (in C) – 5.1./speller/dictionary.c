// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536;
// nw number of words in the dictionary
int nw = -1;                                     
// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{   // OBTAIN text word HASH VALUE (dwhv)
    unsigned int twhv = hash(word);                   

    node *c = table[twhv];                    
    int f;

    if (c == NULL)
    {
        return false;
    }

    else
    {
        // COMPARE UNTIL REACH THE END OF THE LINKED LISTS
        while (c != NULL)                                                 
        {   // COMPARE THE TEXT' WORD TO THE WORD IN TE CURRENT NODE
            f = strcasecmp(c->word, word);          
            // if the text word is found
            if (f == 0)                                   
            {
                c = NULL;

            }

            else                                             
            {   // MOVE THE CURSOR TO THE NEXT NODE
                c = c->next;
            }
        }

    }

    if (f == 0)
    {
        return true;
    }

    else
    {
        return false;
    }


}

// Hashes word to a number
unsigned int hash(const char *word)          //https://gist.github.com/yangrq1018/e769abd7489ea8f52351b30829796a15
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;

}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dico = fopen(dictionary, "r");    // open the dictionary
    if (dico == NULL)
    {
        return false;
    }

    else
    {
        while (!feof(dico))
        {
            nw++;
            char wrd [LENGTH + 1];
            fscanf(dico, "%s", wrd);                   // Read string for file

            node *n = malloc(sizeof(node));            // Create a new node for each word
            char *wcp = strcpy(n->word, wrd);

            unsigned int dwhv = hash(wcp);             // Obtain dictionary word HASH VALUE (dwhv)

            n->next = table[dwhv];                     // the new word's node point on the head of the linked lists to which it belongs
            table[dwhv] = n ;                          // table[hv] point now on the new word's node

        }
        fclose(dico);
        return true;
    }
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{

    return nw;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int n;
    // FOR EACH "BUCKET"
    for (n = 0; n < N; n++)  
    {
        node *c = table[n];
        // Until reach the end of the current linked list  LIST
        while (c != NULL)               
        {
            node *tmp = c;

            c = c -> next;
            free(tmp);

        }

    }


    return true;
}
