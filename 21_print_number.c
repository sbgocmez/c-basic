#include <stdio.h>
#include <stdlib.h>

/**
 * Print the English text for a digit.
 *
 * @param digit the digit to print
 */
void print_digit(int digit)
{
    switch (digit) {
        case 1:
            printf("one");
            break;
        case 2:
            printf("two");
            break;
        case 3:
            printf("three");
            break;
        case 4:
            printf("four");
            break;
        case 5:
            printf("five");
            break;
        case 6:
            printf("six");
            break;
        case 7:
            printf("seven");
            break;
        case 8:
            printf("eight");
            break;
        case 9:
            printf("nine");
            break;
    }
}

/**
 * Print the English text for a number between 10 and 19.
 *
 * @param number the number to print, 10 <= number <= 19
 */
void print_teen(int number)
{
    switch (number) {
        case 10:
            printf("ten");
            break;
        case 11:
            printf("eleven");
            break;
        case 12:
            printf("twelve");
            break;
        case 13:
            printf("thirteen");
            break;
        case 14:
            printf("fourteen");
            break;
        case 15:
            printf("fifteen");
            break;
        case 16:
            printf("sixteen");
            break;
        case 17:
            printf("seventeen");
            break;
        case 18:
            printf("eighteen");
            break;
        case 19:
            printf("nineteen");
            break;
    }
}

/**
 * Print the English text for the tens digit of a number.
 *
 * @param number the number to print
 */
void print_tens(int number)
{
    if (number >= 90) {
        printf("ninety");
    } else if (number >= 80) {
        printf("eighty");
    } else if (number >= 70) {
        printf("seventy");
    } else if (number >= 60) {
        printf("sixty");
    } else if (number >= 50) {
        printf("fifty");
    } else if (number >= 40) {
        printf("forty");
    } else if (number >= 30) {
        printf("thirty");
    } else if (number >= 20) {
        printf("twenty");
    }
}

/**
 * Print the English text for a number.
 *
 * @param number the number to print, 0 < number < 100
 */
void print_num(int number)
{
    int remaining = number;

    if (remaining >= 100) {
        int hundreds = remaining / 100;
        print_digit(hundreds);
        printf("hundred");
        remaining = remaining % 100;
    }

    if (remaining >= 20) {
        print_tens(remaining);
        remaining = remaining % 10;
    } else if (remaining >= 10) {
        print_teen(remaining);
        remaining = 0;
    }

    if (remaining > 0) {
        print_digit(remaining);
    }
}

int main()
{
    print_num(274);
    printf("\n");

    print_num(50);
    printf("\n");

    print_num(819);
    printf("\n");
	
	print_num(13);
	printf("\n");
    return EXIT_SUCCESS;
}