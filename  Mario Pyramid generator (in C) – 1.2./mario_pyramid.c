#include <stdio.h>
#include<cs50.h>

int main(void)
{    
    int n;
    do  
    {
        n = get_int("Height: ");       // USER INPUT DESIRED PYRAMID'S HEIGHT
    }
    while (n < 1 || n > 8);            // PYRAMID'S HEIGHT MUST BE IN [1,8], OTHERWISE PROMPT AGAIN
     
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)             // FOR EACH LEVEL
        {  
            for (int z = 1; z < n - i; z++)
            {
                printf(" ");
            }
            for (j = 0;  j <= i; j++)
            {
                printf("#");
            }     
        }
        printf("\n");
    }
}
