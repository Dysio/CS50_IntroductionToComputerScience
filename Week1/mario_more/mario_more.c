#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do 
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n >= 9);
    
    for (int i = 1; i <= n; i++)
    {
        for (int space = 0; space < n - i; space++)
        {
            printf(" ");
        }
        for (int hash = 0; hash < i; hash++)
        {
            printf("#");
        }
        
        printf("  ");
        
        for (int hash = 0; hash < i; hash++)
        {
            printf("#");
        }
        
        
        printf("\n");
    }
}
