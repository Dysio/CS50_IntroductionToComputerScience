#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("Change: ");
    }
    while (change <= 0);

    int cents = round(change * 100);
    
    int coins = 0;
    
    do
    {
        if (cents - 25 >= 0)
        {
            cents = cents - 25;
            coins++;
        }
        else if (cents - 10 >= 0)
        {
            cents = cents - 10;
            coins++;
        }
        else if (cents - 5 >= 0)
        {
            cents = cents - 5;
            coins++;
        }
        else 
        {
            cents = cents - 1;
            coins++;
        }
        
    }
    while (cents > 0);
    
    printf("%i", coins);
}
