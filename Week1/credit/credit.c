#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //printf("%lu", sizeof(long));
    long n, card_number;
    int i, sum1, sum2;
    card_number = get_long("Number: ");
    n = card_number;

    // Checking the sum of numbers beginning with last one till next by 2
    // 4003600000000014 -> 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0
    sum1 = 0;
    while (n > 0)
    {
        i = n % 10;
        n = n / 100;

        sum1 = sum1 + i;
    }

    // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together
    // 4003600000000014 -> 1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2
    // 2 + 0 + 0 + 0 + 0 + 12 + 0 + 8 -> 2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13
    sum2 = 0;
    n = card_number / 10;
    while (n > 0)
    {
        i = n % 10;
        n = n / 100;

        i = i * 2;
        // Check if number is higher than 10 in case of adding two digits: 12 -> 1+2=3
        if (i / 10 > 0)
        {
            int j = i % 10;
            i = i / 10;
            i = i + j;
        }
        sum2 = sum2 + i;
    }

    n = card_number;

    int sum = sum1 + sum2;
    if (sum % 10 == 0 && card_number > 1e12)
    {
        if (n / (long)1e13 == 34 || n / (long)1e13 == 37)
        {
            printf("AMEX\n");
        }
        else if (card_number / (long)1e14 >= 51 && card_number / (long)1e14 <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (card_number / (long)1e12 == 4 || card_number / (long)1e15 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    //printf("%li", (long)4222222222222/(long)1e12);
}
