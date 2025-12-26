#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open the forensic image file
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    FILE *outFile = NULL;
    char filename[8];
    int fileCount = 0;
    bool foundJpg = false;

    // Read the card file block by block
    while (fread(buffer, sizeof(uint8_t), BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        // Check if the block is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If already found a JPEG, close the previous one
            if (foundJpg)
            {
                fclose(outFile);
            }

            // Create a new JPEG file
            sprintf(filename, "%03d.jpg", fileCount);
            outFile = fopen(filename, "w");
            if (outFile == NULL)
            {
                fclose(card);
                printf("Could not create %s.\n", filename);
                return 1;
            }

            fileCount++;
            foundJpg = true;
        }

        // Write to the current JPEG file if a JPEG has been found
        if (foundJpg)
        {
            fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, outFile);
        }
    }

    // Close any remaining files
    if (foundJpg)
    {
        fclose(outFile);
    }

    // Close the card file
    fclose(card);

    return 0;
}
