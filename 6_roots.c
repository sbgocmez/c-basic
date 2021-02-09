#include<stdio.h>
#include<math.h>

int main()
{
	double a = 0, b = 0, c = 0;
	printf("Forn an equation such that a*x*x + b*x + c = 0, give a, b, c respectively to find it's roots.\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	double discriminant = (b * b) - (4 * a * c);
	
	if (discriminant < 0){
		printf("This equation has no real roots.\n");
	}
	else {
		double x1 = ((-b) - sqrt(discriminant)) / (2.0 * a);
		double x2 = ((-b) + sqrt(discriminant)) / (2.0 * a);
		
		if (discriminant == 0){
			printf("Your roots are same and they are : %lf\n", x1);
		}
		else {
			printf("Your roots are %lf and %lf.\n", x1, x2);
		}
	}
	
	return 0;
}