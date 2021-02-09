#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;
	double n;
	double a;
	double k;
	printf("Enter the temperature: "); scanf("%lf %c", &n, &c);
	k = n;
	if (c == 'F' || c == 'f') {
		k = 5.0 / 9 * (k - 32);
	}
	
	printf("Enter the altitude: "); scanf("%lf", &a);
	
	if (c == 'F' || c == 'f') {
		if (n < 32)
			printf("solid!\n");
		else if (n >= 32 && n < (212 - k/300))
			printf("liquid!\n");
		else
			printf("gas!\n");
	}
	else if (c == 'C' || c == 'c') {
		if (n < 0)
			printf("solid!\n");
		else if (n >= 0 && n < (100 - a/300))
			printf("liquid!\n");
		else
			printf("gas!\n");
	}
}