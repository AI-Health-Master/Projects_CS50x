#include <stdio.h>
#include<cs50.h>
#include <math.h>

int main(void)
{
    float x;        // Change owed
    int n;         // Number of coins

    do 
    {
        x = get_float("Change owed:  ");
    }
    while (x < 0);                         // Reprompt the user if enter a negative number

    x = round(x * 100);    

    for (n = 0; x >= 25;)       //Number of quarters (25c)
    {   
        x -= 25;
        n++;
    }

    for (; x >= 10;)            //Number of dimes (10c)
    {
        x -= 10;
        n++;
    }

      
    for (; x >= 5;)              //Number of nickels (5c)
    {
        x -= 5;
        n++;
    }
      
    for (; x >= 1;)              //Number of pennies (1c)
    {
        x -= 1;
        n++;
    }



    printf("%i\n", n);        // RESULT
}
