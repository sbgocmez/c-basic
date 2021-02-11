#include <stdio.h>
#include <stdlib.h>

typedef struct Fraction
{
	int numerator;
	int denominator;
} Fraction;

Fraction getFraction(void) //use scanf
{
	Fraction fr;
	printf("Write a fraction in the form of x/y: ");
	scanf("%d/%d", &fr.numerator, &fr.denominator);
	return fr;
}

Fraction multiplyFrac(Fraction fr1, Fraction fr2)
{
	Fraction res;

	res.numerator = fr1.numerator * fr2.numerator;
	res.denominator = fr1.denominator * fr2.denominator;

	return res;
}

void printFraction(Fraction fr1, Fraction fr2, Fraction result)
{
	printf("\n The result of %d/%d * %d/%d is %d/%d \n", fr1.numerator, fr1.denominator,
		   fr2.numerator, fr2.denominator, result.numerator, result.denominator);
}

int main()
{
	Fraction fr1;
	Fraction fr2;
	Fraction result;

	fr1 = getFraction();
	fr2 = getFraction();

	result = multiplyFrac(fr1, fr2);
	printf("Multiplication of (%d/%d)*(%d/%d) is %d/%d ", fr1.numerator, fr1.denominator, fr2.numerator, fr2.denominator, result.numerator, result.denominator);
	return EXIT_SUCCESS;
}