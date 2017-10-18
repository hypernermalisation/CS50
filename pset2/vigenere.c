#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Verify only two command line arguments are passed, otherwise exit
    if (argc != 2)
    {
        printf("One argument required. Exiting.\n");
        return 1;
    }
        // Check if non-alpha character exists in keyword argument
    else
    {
        for (int i = 0, argl = strlen(argv[1]); i < argl; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Non-alpha character in keyword found. Exiting.");
                return 1;
            }
        }
    }

    // Get plaintext from user to be encoded
    printf("Enter text to be encoded: ");
    string plaintext = get_string();
    printf("plaintext:  %s\n", plaintext);
    printf("ciphertext: ");

    // Key values
    char* key = argv[1];
    int keylength = strlen(key);


    // Encode each character in plain text
    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        // Check for alpha characters
        if isalpha(plaintext[i])
        {
            // Get ascii value for alpha character
            int ascii = (int)plaintext[i];

            // ascii values for upper case are 65-90
            if isupper(plaintext[i])
            {
                int cipher = (((ascii - 65 + (int)toupper(key[i % keylength]) -65) % 26) + 65);
                printf("%c", (char)cipher);
            }

            // ascii values for lower case are 97-122
            if islower(plaintext[i])
            {
                int cipher = (((ascii - 97 + (int)tolower(key[i % keylength]) -97) % 26) + 97);
                printf("%c", (char)cipher);
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
