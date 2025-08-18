#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //FOR EACH PIXEL
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float b = image[h][w].rgbtBlue;                         // COPY
            float g = image[h][w].rgbtGreen;
            float r = image[h][w].rgbtRed;

            image[h][w].rgbtBlue = round((b + g + r) / 3);                 // MAKE AVERAGE OF THE THREE COLOR
            image[h][w].rgbtGreen = round((b + g + r) / 3);
            image[h][w].rgbtRed =  round((b + g + r) / 3);
        }

    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float b = image[h][w].rgbtBlue;
            float g = image[h][w].rgbtGreen;
            float r = image[h][w].rgbtRed;

            int R = round(0.393 * r + 0.769 * g + 0.189 * b);          //SEPIA'S ALGORITHM
            int G = round(0.349 * r + 0.686 * g + 0.168 * b);
            int B =  round(0.272 * r + 0.534 * g + 0.131 * b);


            if (R >= 255)                                         // THE COLOR RED MUST BE <= 255
            {

                image[h][w].rgbtRed = 255;

            }

            else
            {
                image[h][w].rgbtRed = R;
            }

            if (G >= 255)                                      // THE COLOR GREEN MUST BE <= 255
            {

                image[h][w].rgbtGreen = 255;

            }
            else
            {
                image[h][w].rgbtGreen = G;
            }


            if (B >= 255)                                        // THE COLOR BLUE MUST BE <= 255
            {

                image[h][w].rgbtBlue = 255;
            }
            else
            {
                image[h][w].rgbtBlue = B;
            }



        }


    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE Array[height][width];

    for (int h = 0; h < height; h++)                         // COPY THE IMAGE IN THE NEW ARRAY
    {
        for (int w = 0; w < width; w++)
        {
            Array[h][w].rgbtBlue = image[h][w].rgbtBlue;
            Array[h][w].rgbtGreen = image[h][w].rgbtGreen;
            Array[h][w].rgbtRed = image[h][w].rgbtRed;

        }

    }




    for (int h = 0; h < height; h++)                               // REFLECT
    {
        for (int w = 0; w < width; w++)
        {


            int bn = Array[h][width - 1 - w].rgbtBlue;
            int gn = Array[h][width - 1 - w].rgbtGreen;
            int rn = Array[h][width - 1 - w].rgbtRed;

            image[h][w].rgbtBlue = bn;
            image[h][w].rgbtGreen = gn;
            image[h][w].rgbtRed = rn;
        }

    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE src[height][width];
    // Copy source so we don’t read blurred pixels mid-pass
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            src[i][j] = image[i][j];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumR = 0, sumG = 0, sumB = 0, cnt = 0;

            // 3x3 neighborhood
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di, nj = j + dj;
                    if (ni < 0 || ni >= height || nj < 0 || nj >= width) continue;
                    sumR += src[ni][nj].rgbtRed;
                    sumG += src[ni][nj].rgbtGreen;
                    sumB += src[ni][nj].rgbtBlue;
                    cnt++;
                }
            }

            image[i][j].rgbtRed   = (BYTE)roundf((float)sumR / cnt);
            image[i][j].rgbtGreen = (BYTE)roundf((float)sumG / cnt);
            image[i][j].rgbtBlue  = (BYTE)roundf((float)sumB / cnt);
        }
    }
}
