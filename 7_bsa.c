#include<stdio.h>
#include<math.h>

int main()
{
	double weight = 0, height = 0;
	printf("Enter your weight (gr), height (cm)\n");
	scanf("%lf %lf", &weight, &height);
	
	double bsa = 0.0003207 * pow(height, 0.3) * pow(weight, (0.7285 - (0.0188 * log(weight))));
	printf("Your bsa is %lf\n", bsa);
	
	return 0;
}