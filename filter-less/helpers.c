#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int averagergb =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = averagergb;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = image[i][j].rgbtRed * 0.393 + image[i][j].rgbtGreen * 0.769 +
                       image[i][j].rgbtBlue * 0.189;
            sepiaGreen = image[i][j].rgbtRed * 0.349 + image[i][j].rgbtGreen * 0.686 +
                         image[i][j].rgbtBlue * 0.168;
            sepiaBlue = image[i][j].rgbtRed * 0.272 + image[i][j].rgbtGreen * 0.534 +
                        image[i][j].rgbtBlue * 0.131;

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = buffer;
        }
    }
    return;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_secondary[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float sumred = 0, sumgreen = 0, sumblue = 0, pixtotnum = 0;
            for (int inew = i - 1; inew <= i + 1; inew++)
            {
                for (int jnew = j - 1; jnew <= j + 1; jnew++)
                {
                    if (inew >= 0 && jnew >= 0 && inew < height && jnew < width)
                    {
                        sumred += image[inew][jnew].rgbtRed;
                        sumgreen += image[inew][jnew].rgbtGreen;
                        sumblue += image[inew][jnew].rgbtBlue;
                        pixtotnum++;
                    }
                }
            }
            image_secondary[i][j].rgbtRed = round(sumred / pixtotnum);
            image_secondary[i][j].rgbtGreen = round(sumgreen / pixtotnum);
            image_secondary[i][j].rgbtBlue = round(sumblue / pixtotnum);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image_secondary[i][j];
        }
    }
    return;
}
