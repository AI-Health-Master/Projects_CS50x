#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // OPEN MEMORY CARD
    FILE *ptr = fopen(argv[1], "r");                    

    if (ptr == NULL)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    int n = -1;
    // REPEAT UNTIL END CARD
    while (!feof(ptr))                   
    {
        unsigned char AllB [512];
        // READ 512 BYTES INTO A BUFFER
        fread(AllB, 512, 1, ptr);                    


        // IF IT IS THE START OF NEW JPEG
        if (AllB[0] == 0xff && AllB[1] == 0xd8 && AllB[2] == 0xff && ((AllB[3] & 0xe0) == 0xe0)) 
        {
            n++;
            // IF FIRST JPEG
            if (n == 0)                   
            {
                char fnme[8];                                  // JPEG's NAME
                sprintf(fnme, "%03d.jpg", n);

                FILE *img = fopen(fnme, "w");                   // OPEN FIRST JPEG
                fwrite(AllB, 512, 1, img);
                fclose(img);

            }
            // ELSE NOT THE FIRST
            else                            
            {
                char fnme[8];
                sprintf(fnme, "%03i.jpg", n);

                FILE *img = fopen(fnme, "w");
                fwrite(AllB, 512, 1, img);
                fclose(img);

            }
        }




        else
        {   // IF ALREADY FOUND JPEG
            if (n  >= 0)                
            {
                char fnme[8];
                sprintf(fnme, "%03i.jpg", n);

                FILE *img = fopen(fnme, "a");
                fwrite(AllB, 512, 1, img);
                fclose(img);
            }
            // IF JPEG NEVER FOUND
            else                     
            {
                ;
            }
        }

    }


    // CLOSE CARD.RAW
    fclose(ptr);             
    return 0;

}
