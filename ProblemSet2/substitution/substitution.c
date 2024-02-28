#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool CheckValidKey(string key);
string SubstituteCipher(string key, string input);

int main(int argc, string argv[])
{

    // Accept just one arg
    if (argc != 2)
    {
        printf("Please provide a key as the argument!\n");
        return 1;
    }

    string key = argv[1];

    if (!CheckValidKey(key))
    {
        printf("The key is invalid!\n");
        return 1;
    }

    // Ask for the values
    string plainText = get_string("plaintext: ");
    printf("ciphertext: %s\n", SubstituteCipher(key, plainText));
}

string SubstituteCipher(string key, string input)
{
    for (int i = 0, length = strlen(input); i < length; i++)
    {
        // Only sub if the index is alpha.
        if (isalpha(input[i]))
        {
            char shift = isupper(input[i]) ? 'A' : 'a';

            // Letter is upper, use upper-case key
            if (isupper(input[i]))
            {
                input[i] = toupper(key[input[i] - shift]);
            }
            else
            {
                input[i] = tolower(key[input[i] - shift]);
            }
        }

        // else leave the character alone
    }

    return input;
}

bool CheckValidKey(string key)
{

    int keyLength = strlen(key);
    bool used[26] = {false};

    // Key must be 26 characters
    if (keyLength != 26)
    {
        return false;
    }

    // Check all characters are alphabetic, and only used once
    for (int i = 0; i < keyLength; i++)
    {

        // Check alphabetic
        if (!(isalpha(key[i])))
        {
            return false;
        }

        // convert the char to lower
        char c = tolower(key[i]);

        // Check if the char was used prior
        if (used[c - 'a'])
        {
            return false;
        }

        // Mark the letter as used
        used[c - 'a'] = true;
    }

    // Key is valid
    return true;
}
