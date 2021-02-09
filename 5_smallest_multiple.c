#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* 2520 is the smallest number that can be divided by each of the numbers
 * from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

// Program to find smallest positive number that is evenly divisible by all of the numbers from 1 to n
// it would be better if we use long int instead of int.

bool isPrime(int number)
{
	int copy = number;
	if (number == 2)
		return true;
	// find largest prime of number
	else
	{
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
	}
	// if largest prime is equal to number itself, number is prime.
	if (copy == number)
		return true;
	return false;
}

int how_many_times(int number, int prime)
{
	int copy;
	int count = 0, most = 0;

	for (int i = prime; i <= number; i += prime)
	{
		copy = i;
		while (copy % prime == 0)
		{
			count++;
			copy /= prime;
		}
		if (count > most)
			most = count;
		count = 0;
	}
	return most;
}

int main()
{
	int n, num = 1;
	printf("Program to find smallest positive number that is evenly divisible by all of the numbers from 1 to n, n: ");
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
	{
		if (isPrime(i))
			num = num * pow((double)(i), (double)(how_many_times(n, i)));
	}

	printf("%d ", num);
	return EXIT_SUCCESS;
}