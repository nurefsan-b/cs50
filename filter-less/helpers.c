#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE blue = image[i][j].rgbtBlue;
            BYTE green = image[i][j].rgbtGreen;
            BYTE red = image[i][j].rgbtRed;
            BYTE average = round((red + green + blue) / 3.0);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE originalBlue = image[i][j].rgbtBlue;
            BYTE originalGreen = image[i][j].rgbtGreen;
            BYTE originalRed = image[i][j].rgbtRed;

            int sepiaBlue = round((.272 * originalRed) + (.534 * originalGreen) + (.131 * originalBlue));
            int sepiaGreen = round((.349 * originalRed) + (.686 * originalGreen) + (.168 * originalBlue));
            int sepiaRed = round((.393 * originalRed) + (.769 * originalGreen) + (.189 * originalBlue));
            if(sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if(sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if(sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int length = width - 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][length-j];
            image[i][length-j] = temp;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width]) {
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
        int red = 0;
        int green = 0;
        int blue = 0;
        int count = 0;

        for (int i2 =-1; i2 <= 1; i2++)
        {
            for(int j2 =-1; j2 <= 1; j2++)
            {
                int ni = i+i2;
                int nj = j+j2;

                if(ni>=0 && ni<height && nj>=0 &&nj<width){
                    red += temp[ni][nj].rgbtRed;
                    green += temp[ni][nj].rgbtGreen;
                    blue += temp[ni][nj].rgbtBlue;
                    count++;
                }
            }
        }

        image[i][j].rgbtRed = round((float)red/count);
        image[i][j].rgbtGreen = round((float)green/count);
        image[i][j].rgbtBlue = round((float)blue/count);
        }
    }
    return;
}
