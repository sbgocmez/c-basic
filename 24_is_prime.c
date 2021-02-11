#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//i think closer to correct now..

int main()
{
	int number = 0;
	printf("Enter a number:\n");
	scanf("%d", &number);
	int target = sqrt(number);
	int target_init = 2;

	if (number <= 1)
	{
		printf("It's not prime!\n");
		return EXIT_FAILURE;
	}

	else if (number == 2 || number == 3)
	{
		printf("It's prime!\n");
		return EXIT_FAILURE;
	}

	while (target_init <= target)
	{
		int mod = (number % target_init);
		if (mod == 0)
		{
			printf("%d is not prime!\n", number);
			return EXIT_FAILURE;
		}
		else
		{
			if (target_init < target)
				target_init++;
			else
			{
				printf("%d is prime!\n", number);
				return EXIT_FAILURE;
			}
		}
	}
	return 0;
}