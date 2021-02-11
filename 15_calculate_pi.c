#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// calculating PI via Carlo Method, using relation between areas of square and in-circle
double getRandom(double u, double l)
{
	return l + (u - l) * rand() / RAND_MAX;
}
double calculatePi(int max_iteration)
{
	double x, y;
	int in_Circle = 0;
	for (int i = 0; i < max_iteration; i++)
	{
		x = getRandom(-1, 1);
		y = getRandom(-1, 1);
		if (x * x + y * y <= 1)
			in_Circle++;
	}
	return (in_Circle * 4.0 / max_iteration);
}
int main()
{
	int max_iteration = 1000;
	srand(time(NULL));
	double pi = calculatePi(max_iteration);
	printf("Pi is %lf and iteartions: %d", pi, max_iteration);
	return EXIT_SUCCESS;
}