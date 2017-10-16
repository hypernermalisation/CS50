#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Get user input for name and upper case the first letter of each name part

int main(void)
{
    string name = get_string();

    // Check for first letter
    if (name[0] != '\0' && name[0] != ' ')
    {
        printf("%c", toupper(name[0]));
    }

    // Check for next whitespace then print next found letter
    for (int i = 0, l = strlen(name); i < l; i++)
    {
        if (name[i] == ' ')
        {
            if (name[i+1] != ' ' && name[i+1] != '\0')
            {
                printf("%c", toupper(name[i+1]));
            }
        }
    }

    printf("\n");
}
