#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototypes
bool VerifyCard(char *cardNumber);
void IdentifyCardType(char *cardNumber);

int main(void)
{
    // Large enough char array to hold the card number
    char cardNumber[20];

    do
    {
        printf("Card Number: ");
        scanf("%19s", cardNumber); // Room for null terminator and prevent buffer overflow.
    }
    while (strlen(cardNumber) == 0);

    IdentifyCardType(cardNumber);
}

// Identify Card Type based on given rules
void IdentifyCardType(char *cardNumber)
{
    int cardLength = strlen(cardNumber);

    if (VerifyCard(cardNumber))
    {
        // AMEX - 15-digits, starts with 34 or 37
        if (cardLength == 15 && cardNumber[0] == '3' && (cardNumber[1] == '4' || cardNumber[1] == '7'))
        {
            printf("AMEX\n");
        }
        // MASTERCARD - 16 digits, starts with 51, 52, 53, 54, or 55
        else if (cardLength == 16 && cardNumber[0] == '5' && (cardNumber[1] >= '1' && cardNumber[1] <= '5'))
        {
            printf("MASTERCARD\n");
        }
        // VISA - 13 or 16 digits, starts with 4
        else if ((cardLength == 13 || cardLength == 16) && cardNumber[0] == '4')
        {
            printf("VISA\n");
        }
        // Didnt match any of our rules...
        else
        {
            printf("INVALID\n");
        }
    }
    // Didnt match any of our rules...
    else
    {
        printf("INVALID\n");
    }
}

// Luhn's Algorithm
bool VerifyCard(char *cardNumber)
{
    /*
    Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    Add the sum to the sum of the digits that weren’t multiplied by 2.
    If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    */
    int cardLength = strlen(cardNumber);
    bool mulDigit = false;
    int sum = 0;

    for (int n = cardLength - 1; n >= 0; n--)
    {

        // Verify the char is a digit, if not, return false
        if (!isdigit(cardNumber[n]))
        {
            return false;
        }

        // Convert the char to a digit
        int digit = cardNumber[n] - '0';

        // Is this a multiply digit? If so, then we multiply by 2
        if (mulDigit)
        {
            digit *= 2;

            // If the digit is over 10, mod it by 10, then add 1, since 9 * 2 = 18, 1 + 8 if you split the digits
            if (digit >= 10)
            {
                digit = (digit % 10) + 1;
            }
        }

        // Flip the mulDigit flag
        mulDigit = !mulDigit;

        // Add the digit to the sum
        sum += digit;
    }

    // Return should be true if sum % 10 == 0
    return ((sum % 10) == 0);
}
