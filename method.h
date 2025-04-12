#include <stdbool.h>
int getCurrencyChoice();
int getAmount(int CurrencyType);
void calculateCoins(int CurrencyType, int numOfAmount, int *numOfFiftyCents, int *numOfTwentyFiveCents, int *numOfTwentyCents, int *numOfTenCents, int *numOfFiveCents, int *numOfOneCent);
void displayResult(int CurrencyType, int numOfFiftyCents, int numOfTwentyFiveCents, int numOfTwentyCents, int numOfTenCents, int numOfFiveCents, int numOfOneCent);
bool CheckValidAmount(int CurrencyType, int numOfAmount);
void calculateCoinsUS(int numOfAmount, int *numOfFiftyCents, int *numOfTwentyFiveCents,  int *numOfTenCents, int *numOfOneCent);
void calculateCoinAU(int numOfAmount, int *numOfFiftyCents, int *numOfTwentyCents, int *numOfTenCents, int *numOfFiveCents);
void calculateCoinsEuro(int numOfAmount,   int *numOfTwentyCents, int *numOfTenCents, int *numOfFiveCents, int *numOfOneCent);
