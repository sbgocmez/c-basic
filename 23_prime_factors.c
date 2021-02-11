#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 0;
	printf("the number: "); scanf("%d", &num);
	printf("the number is: ");
	int prime = 2;
	for (prime = 2; num!= 1; prime++) {
		int count = 0;
		while (num % prime == 0) {
			num = num / prime;
			count++;
		}
		if (count > 0)
			printf("%d^%d*", prime, count);
	}
	
	return EXIT_SUCCESS;
}