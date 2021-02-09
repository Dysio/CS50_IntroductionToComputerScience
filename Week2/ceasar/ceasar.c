#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // Check if all character are digits
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]))
            {
                // If character is digit continue
                continue;
            }
            else
            {
                // If character in argument vector 1 is not digit end function returning 1
                printf("Usage: %s key\n", argv[0]);
                return 1;
            }
        }

        // Getting key value from command line argument vector
        int key = atoi(argv[1]);

        string plaintext = get_string("plaintext: ");
        // string ciphertext = "";
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // Check if char is alphabetic
            if (isalpha(plaintext[i]))
            {
                // Check if char is uppercase 
                if (plaintext[i] < 'a')
                {
                    // ASCII num of A is 65
                    printf("%c", 65 + (plaintext[i] - 65 + key) % 26);
                }
                else
                {
                    // ASCII num for a is 97
                    printf("%c", 97 + (plaintext[i] - 97 + key) % 26);
                }
                
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");

    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
}
