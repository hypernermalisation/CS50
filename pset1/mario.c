#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Input for amount of how high to build the pyramid
    do {
        printf("Provide a height between 1-23\n");
        height = get_int();
    }
    while(height < 0 || height >= 24);

    for (int row = 0; row < height; row++)
    {
        // Left side of Pyramid
        for (int spaces = height - row; spaces > 1; spaces--)
        {
            printf(" ");
        }
        for (int hashes = 0; hashes < row + 1; hashes++)
        {
            printf("#");
        }

        // Print two space gap between pyramids
        printf("  ");

        // Right side of Pyramid
        for (int hashes = 0; hashes < row + 1; hashes++)
        {
            printf("#");
        }

        printf("\n");
    }
}