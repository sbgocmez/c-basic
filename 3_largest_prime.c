#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//SOLVED
/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
*/
int main()
{
	long int number, copynum;
	printf("Number: ");
	scanf("%ld", &number);
	copynum = number;

	if (number % 2 == 0)
	{
		while (number % 2 == 0)
		{
			if (number / 2 != 1)
				number /= 2;
			else
				break;
		}
	}

	for (int i = 3; i <= sqrt(number); i += 2)
	{
		while (number % i == 0)
		{
			if (number / i != 1)
				number /= i;
			else
				break;
		}
	}

	printf("%ld is the largest prime factor of %ld.", number, copynum);

	return EXIT_SUCCESS;
}