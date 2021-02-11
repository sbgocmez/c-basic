#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//VECTOR STRUCTURE
typedef struct
{
	int x, y;
} vector;

//PRINT VECTORS
void printVectors(vector *v)
{
	printf("vector is: (%d, %d)\n", v->x, v->y);
}
//ADD VECTORS
void addVectors(vector *v1, vector *v2, vector *v)
{
	v->x = v1->x + v2->x;
	v->y = v1->y + v2->y;
}
//SUBSTRACT VECTORS
void subtractVectors(vector *v1, vector *v2, vector *v)
{
	v->x = v1->x - v2->x;
	v->y = v1->y - v2->y;
}
//FIND MAGNITUDE
double magnitudeVec(vector *v)
{
	double mag = 0;
	mag = sqrt(v->x * v->x + v->y * v->y);
	return mag;
}
//ANGLE OF EACH VECTOR WRT X-AXIS - ARCTAN
double angVec(vector *v)
{
	double tan = v->y * 1.0 / v->x;
	return atan(tan);
}
//ANGLE BETWEEN TWO VECTORS
double angBetween(double a1, double a2)
{
	double angle = fabs(a1 - a2);
	return angle;
}
//DOT PRODUCT
double dotProduct(double m1, double m2, double a)
{
	double product = m1 * m2 * cos(a);
	return product;
}
//CROSS PRODUCT
double crossProduct(double m1, double m2, double a)
{
	double product = m1 * m2 * sin(a);
	return product;
}
//MAIN
int main()
{
	vector vec1, vec2, vec_res;

	vec1.x = 2;
	vec1.y = 2;

	vec2.x = 1;
	vec2.y = 3;

	printVectors(&vec1);
	printVectors(&vec2);

	addVectors(&vec1, &vec2, &vec_res);
	printf("Addition ");
	printVectors(&vec_res);

	subtractVectors(&vec1, &vec2, &vec_res);
	printf("Subtraction ");
	printVectors(&vec_res);
	//ONE RADIAN IS EQUAL TO 57.2958 DEGREES SO WE CONVERT THEM
	printf("Magnitude of vectors respectively: %f and %f\n", magnitudeVec(&vec1), magnitudeVec(&vec2));
	printf("Angle of vectors wrt x-axis respectively: %f and %f\n", 57.2958 * angVec(&vec1), 57.2958 * angVec(&vec2));
	printf("Angle between vectors is: %f\n", 57.2958 * angBetween(angVec(&vec1), angVec(&vec2)));

	printf("dat product: %.2f\n", dotProduct(magnitudeVec(&vec1), magnitudeVec(&vec2), angBetween(angVec(&vec1), angVec(&vec2))));
	printf("cross product: %.2f\n", crossProduct(magnitudeVec(&vec1), magnitudeVec(&vec2), angBetween(angVec(&vec1), angVec(&vec2))));

	return EXIT_SUCCESS;
}