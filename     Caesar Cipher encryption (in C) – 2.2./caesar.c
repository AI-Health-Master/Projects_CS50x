#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])    // COMMMAND LINE ARGUMENT
{
    int n = 0;                       // argv[1][n] CHARACTER NUMBER n+1 OF argv[1]

    if (argc == 2)                       // COUNTING COMMAND LINE ARGUMENT, AND CHECK IF argc == 2
    {

        for (; n < strlen(argv[1]);)                 // VALIDATING THE KEY  (THE KEY = A INTEGER?)    48 is the ASCII code for '0' and 57 is the ASCII code for '9'
        {
            if (argv[1][n] >= 48 && argv[1][n] <= 57)
            {
                n++;
            }

            else
            {
                break;
            }
        }

        if (n == strlen(argv[1]))                              // IF THE NUMBER OF INTEGER IN THE KEY = NUMBER OF CHARACTER IN THE KEY, PROGRAM CAN CONTINUE
        {
            ;
        }

        else if (n != strlen(argv[1]))                         // ELSE, STOP PROGRAM!
        {
            printf("Usage: ./caeser key\n");
            return 1;
        }

    }
    else                                                      // ELSE IF MORE OR LESS THAN 2 COMMAND LINE ARGUMENT (including the program name), STOP PROGRAM TOO!
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }


    int k = atoi(argv[1]);                                    // CONVERT argv[1] --> INTEGER



    string PT = get_string("plaintext: ");                    // USER'S INPUT

    for (int m = 0 ; m <= strlen(PT) ; m++)                   // CYPHER
    {
        if (PT[m] >= 65 && PT[m] <= 90)                             // FOR UPPERCASE LETTER
        {
            PT[m] = PT[m] - 65;
            PT[m] = ((PT[m] + k) % 26) ;                                // CAESAR'S CYPHER
            PT[m] = PT[m] + 65;
        }
        else if (PT[m] >= 97 && PT[m] <= 122)                       // FOR LOWERCASE LETTER
        {
            PT[m] = PT[m] - 97;
            PT[m] = ((PT[m] + k) % 26);                                 // CAESAR'S CYPHER
            PT[m] = PT[m] + 97;

        }
    }


    printf("ciphertext: %s\n", PT);                           // RESULTS
    return 0;
}
