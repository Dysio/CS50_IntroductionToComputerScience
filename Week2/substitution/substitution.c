#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check if is passed exactly one command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    // Check if key consisnt of 26 characters
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }

    // Check if all values from key are characters
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
        if (isalpha(argv[1][i]))
        {
            continue;
        }
        else
        {
            printf("Key must contain 26 characters.");
            return 1;
        }
    
    // Check if all characters in key are unique
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (argv[1][i] == argv[1][j] || argv[1][i] % 32 == argv[1][j] % 32)
            {
                printf("Characters must be unique");
                return 1;
            }
        }
    }
    
    // Save an array with key
    char key[26];
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        key[i] = argv[1][i];
    }
    
    
    // Getting plaintext from user
    string plaintext = get_string("plaintext: ");
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            plaintext[i] = toupper(key[plaintext[i] % 32 - 1]);
        }
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            plaintext[i] = tolower(key[plaintext[i] % 32 - 1]);
        }
        else
        {
            continue;
        }
        
    }
    
    printf("ciphertext: %s\n", plaintext);
    
    
}
