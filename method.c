#include <stdio.h>
#include <stdbool.h>

// Calculates the denomination breakdown for US dollars (50¢, 25¢, 10¢, 1¢)
void calculateCoinsUS(int numOfAmount, int *numOfFiftyCents, int *numOfTwentyFiveCents, int *numOfTenCents, int *numOfOneCent) 
{
    int remainingAmount = numOfAmount; // Tracks the remaining amount to process
    *numOfFiftyCents = remainingAmount / 50; // Calculate number of 50-cent coins
    remainingAmount = remainingAmount % 50;   // Update remaining amount
    *numOfTwentyFiveCents = remainingAmount / 25; // Calculate number of 25-cent coins
    remainingAmount = remainingAmount % 25;   // Update remaining amount
    *numOfTenCents = remainingAmount / 10;   // Calculate number of 10-cent coins
    remainingAmount = remainingAmount % 10;   // Update remaining amount
    *numOfOneCent = remainingAmount / 1;     // Calculate number of 1-cent coins
}

// Calculates the denomination breakdown for Australian dollars (50¢, 20¢, 10¢, 5¢)
void calculateCoinAU(int numOfAmount, int *numOfFiftyCents, int *numOfTwentyCents, int *numOfTenCents, int *numOfFiveCents) 
{
    int remainingAmount = numOfAmount; // Tracks the remaining amount to process
    *numOfFiftyCents = remainingAmount / 50; // Calculate number of 50-cent coins
    remainingAmount = remainingAmount % 50;   // Update remaining amount
    *numOfTwentyCents = remainingAmount / 20; // Calculate number of 20-cent coins
    remainingAmount = remainingAmount % 20;   // Update remaining amount
    *numOfTenCents = remainingAmount / 10;   // Calculate number of 10-cent coins
    remainingAmount = remainingAmount % 10;   // Update remaining amount
    *numOfFiveCents = remainingAmount / 5;   // Calculate number of 5-cent coins
}

// Calculates the denomination breakdown for Euros (20¢, 10¢, 5¢, 1¢)
void calculateCoinsEuro(int numOfAmount, int *numOfTwentyCents, int *numOfTenCents, int *numOfFiveCents, int *numOfOneCent) 
{
    int remainingAmount = numOfAmount; // Tracks the remaining amount to process
    *numOfTwentyCents = remainingAmount / 20; // Calculate number of 20-cent coins
    remainingAmount = remainingAmount % 20;   // Update remaining amount
    *numOfTenCents = remainingAmount / 10;   // Calculate number of 10-cent coins
    remainingAmount = remainingAmount % 10;   // Update remaining amount
    *numOfFiveCents = remainingAmount / 5;   // Calculate number of 5-cent coins
    remainingAmount = remainingAmount % 5;    // Update remaining amount
    *numOfOneCent = remainingAmount / 1;     // Calculate number of 1-cent coins
}

// Calls the appropriate denomination calculation function based on currency type
void calculateCoins(int CurrencyType, int numOfAmount, int *numOfFiftyCents, int *numOfTwentyFiveCents, int *numOfTwentyCents, int *numOfTenCents, int *numOfFiveCents, int *numOfOneCent) 
{
    // Initialize all denomination counts to 0 to avoid undefined behavior
    *numOfTwentyCents = 0;
    *numOfTenCents = 0;
    *numOfFiveCents = 0;
    *numOfOneCent = 0;
    *numOfTwentyFiveCents = 0;
    *numOfFiftyCents = 0;

    // Select the appropriate calculation function based on currency type
    switch(CurrencyType)    
    {   
        case 1: // US dollars
            calculateCoinsUS(numOfAmount, numOfFiftyCents, numOfTwentyFiveCents, numOfTenCents, numOfOneCent);
            break;
        case 2: // Australian dollars
            calculateCoinAU(numOfAmount, numOfFiftyCents, numOfTwentyCents, numOfTenCents, numOfFiveCents);
            break;
        case 3: // Euros
            calculateCoinsEuro(numOfAmount, numOfTwentyCents, numOfTenCents, numOfFiveCents, numOfOneCent);
            break; 
        default: // Invalid currency type
            printf("Invalid input. Please select a valid currency.\n");
    }
}

// Prompts the user to select a currency type and returns the choice
int getCurrencyChoice()
{
    int CurrencyType; // Stores the user's input for currency type
    while(1)
    {
        // Prompt the user to select a currency
        printf("Type in the number to select currency: 1.US$, 2.AU$, 3.Euro€. 0.Quit.\n");
        scanf("%d", &CurrencyType);
        
        // Handle the user's input
        switch(CurrencyType)
        {   
            case 0: // Quit the program
                printf("Program finished.\n");
                return 0;
            case 1: // Select US dollars
                printf("You have selected US$.\n");
                return 1;
            case 2: // Select Australian dollars
                printf("You have selected AU$.\n");
                return 2;
            case 3: // Select Euros
                printf("You have selected Euro€.\n");
                return 3;
            default: // Invalid input
                printf("Invalid input. Please select a valid currency.\n");
                continue; // Loop to re-prompt for input
        }
    }
}

// Validates the input amount based on currency type
bool CheckValidAmount(int CurrencyType, int numOfAmount)
{
    // Check if the amount is within the valid range (1 to 95)
    if(numOfAmount < 1 || numOfAmount > 95)
    {   
        printf("Invalid input. Please enter a number between 1 and 95.\n");
        return false;
    }
    
    // For Australian dollars (CurrencyType == 2), the amount must be a multiple of 5
    if (CurrencyType == 2 && numOfAmount % 5 != 0)
    {
        printf("Invalid input. Please enter a number that is a multiple of 5.\n");
        return false;
    }
    
    return true; // Amount is valid
}

// Prompts the user for an amount and validates it
int getAmount(int CurrencyType)
{
    int numOfAmount; // Stores the user-input amount
    while(1)
    {   
        // Prompt the user to input an amount
        printf("Type in the number of amount: 1-95.\n");
        scanf("%d", &numOfAmount);
        
        // Validate the amount
        if(CheckValidAmount(CurrencyType, numOfAmount) == false)
        {
            continue; // If invalid, re-prompt for input
        }
        
        return numOfAmount; // Return the valid amount
    }
}

// Displays the denomination calculation results
void displayResult(int CurrencyType, int numOfFiftyCents, int numOfTwentyFiveCents, int numOfTwentyCents, int numOfTenCents, int numOfFiveCents, int numOfOneCent)
{
    // Display results based on the currency type
    switch (CurrencyType)
    {
        case 1: // US dollars
            printf("You have %d fifty cents, %d twenty five cents, %d ten cents, and %d one cent.\n", 
                   numOfFiftyCents, numOfTwentyFiveCents, numOfTenCents, numOfOneCent);
            break;
        case 2: // Australian dollars
            printf("You have %d fifty cents, %d twenty cents, %d ten cents, and %d five cents.\n", 
                   numOfFiftyCents, numOfTwentyCents, numOfTenCents, numOfFiveCents);
            break;
        case 3: // Euros
            printf("You have %d twenty cents, %d ten cents, %d five cents, and %d one cent.\n", 
                   numOfTwentyCents, numOfTenCents, numOfFiveCents, numOfOneCent);
            break;
        default: // Invalid currency type
            printf("Invalid input. Please select a valid currency.\n");
            break;
    }
}