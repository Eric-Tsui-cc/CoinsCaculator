#include <stdio.h>
#include "method.h"
#include <stdbool.h>

// Main function: Program entry point, handles user interaction and calls functions for currency calculations
int main() 
{
    int CurrencyType; // Stores the user's chosen currency type (1: US$, 2: AU$, 3: Euro€, 0: Quit)
    int numOfAmount;  // Stores the user-input amount (1-95)
    int fifty, twentyFive, twenty, ten, five, one; // Stores results for each denomination (e.g., 50 cents, 25 cents, etc.)
    
    // Main loop: Continues until the user chooses to quit (inputs 0)
    while(1)
    {
        // Get the user's chosen currency type
        CurrencyType = getCurrencyChoice();
        
        // If the user chooses to quit (input 0), exit the program
        if (CurrencyType == 0) {
            break; 
        }

        // Get the user-input amount, validated based on the currency type
        numOfAmount = getAmount(CurrencyType);
    
        // Calculate the required denominations based on currency type and amount
        calculateCoins(CurrencyType, numOfAmount, &fifty, &twentyFive, &twenty, &ten, &five, &one);

        // Display the calculation results, listing the number of each denomination
        displayResult(CurrencyType, fifty, twentyFive, twenty, ten, five, one);
    }
    
    return 0; // Program exits successfully
}