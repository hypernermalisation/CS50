#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float owed;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    do{
        printf("Change owed: ");
        owed = get_float();
    }
    while(owed <= 0);

    owed = (owed * 100) + 0.1;
    int coins = 0;

    // Quarter check
    while (owed >= 25)
    {
        coins++;
        quarters++;
        owed-= 25;
    }

    // Dime check
    while (owed >= 10)
    {
        coins++;
        dimes++;
        owed-= 10;
    }

    // Nickel check
    while (owed >= 5)
    {
        coins++;
        nickels++;
        owed-= 5;
    }

    // Penny check
    while (owed >= 1)
    {
        coins++;
        pennies++;
        owed-= 1;
    }

    printf("Coins Total:   %i\n", coins);
    printf("Quarters:      %i\n", quarters);
    printf("Dimes:         %i\n", dimes);
    printf("Nickels:       %i\n", nickels);
    printf("Pennies:       %i\n", pennies);
}