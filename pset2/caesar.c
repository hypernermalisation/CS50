#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Verify only two command line arguments are passed, otherwise exit
    if (argc != 2)
    {
        printf("One positive integer argument required. Exiting.\n");
        return 1;
    }

    // Convert command line string argument to integer
    int key = atoi(argv[1]);

    // Get plaintext from user to be encoded
    printf("Enter text to be encoded: ");
    string plaintext = get_string();
    printf("plaintext:  %s\n", plaintext);
    printf("ciphertext: ");

    // Encode each character in plain text
    for (int i = 0, l =strlen(plaintext); i < l; i++)
    {
        // Check for alpha characters
        if isalpha(plaintext[i])
        {
            // Get ascii value for alpha character
            int ascii = (int) plaintext[i];

            // ascii starting value for upper case is 65
            if isupper(plaintext[i])
            {
                int cipher = (((ascii - 65 + key) % 26) + 65);
                printf("%c", (char) cipher);
            }
            // ascii starting value for lower case is 97
            if islower(plaintext[i])
            {
                int cipher = (((ascii - 97 + key) % 26) + 97);
                printf("%c", (char) cipher);
            }
        }
            // Print non-alpha characters, non-ciphered
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}