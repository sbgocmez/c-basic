#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// program to find largest palindrome made from the product of two n-digit numbers.

bool isPolindrome(int num)
{
    int return_val = 0;
    int number = num;
    while (num != 0)
    {
        return_val *= 10;
        return_val += num % 10;
        num = num / 10;
    }
    return return_val == number;
}

int main()
{
    double n;
    int low, up, largestP = 0;
    printf("Program to find largest palindrome made from the product of two n - digit numbers, n: ");
    scanf("%lf", &n);

    low = (int)(pow(10, (n - 1)));
    up = (int)(pow(10, n) - 1);

    for (int i = up; i >= low; i--)
    {
        for (int j = up; j >= low; j--)
        {
            if (isPolindrome(i * j) && i * j > largestP)
                largestP = i * j;
        }
    }

    printf("Largest palindrome made from the product of two %.1lf-digit numbers is: %d\n", n, largestP);
    return EXIT_SUCCESS;
}