#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string t;
    float l;      // NUMBER OF LETTERS
    float w;     // NUMBER OF WORDS
    float scs;    // NUMBER OF SENTENCES
    int g;     // GRADE OR COLEMAN-LIAU INDEX

    t = get_string("Text: ");      // USER GIVE A TEXT

    l = count_letters(t);
    w = count_words(t);
    scs = count_sentences(t);

    // CALCULATE COLEMAN-LIAU INDEX
    g = round((0.0588 * ((l * 100) / w)) - 0.296 * ((scs * 100) / w) - 15.8);


    if (g >= 1 && g < 16)            // RESULTS
    {
        printf("Grade %i\n", g);
    }
    
    else if (g < 1)
    {
        printf("Before Grade 1\n");
    }
    
    else
    {
        printf("Grade 16+\n");
    }
}


// DETERMINE NUMBER OF LETTERS
int count_letters(string s)
{
    int n = 0;     //NUMBERS OF LETTERS


    for (int i = 0 ; i <= strlen(s); i++)
    {
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            n++;
        }
    }

    return n;
}



// DETERMINE NUMBER OF WORDS
int count_words(string s)
{
    int n = 1;       // NUMBER OF WORDS

    for (int i = 0; i <= strlen(s); i++)
    {
        if (s[i] == 32)  // ASCII for White space
        {
            n++;
        }
    }
    return n;
}



// DETERMINE NUMBER OF SENTENCES
int count_sentences(string s)
{
    int n = 0;          // NUMBER OF SENTENCES

    for (int i = 0; i <= strlen(s); i++)
    {
        if (s[i] == 46  || s[i] == 33   || s[i] == 63)   // ASCII for "!", ".", or "?"
        {
            n++;
        }
    }

    return n;
}


