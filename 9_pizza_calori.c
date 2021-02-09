#include <stdio.h>

int main()
{
	int pizza_type = 0;
	int slice = 0;
	const double pi = 3.1415;
	//radius of big 20, of middle 16, of small 12. each pizza has 6 slices.

	printf("select the type of pizza (1 for big, 2 for medium or 3 for small): \n");
	scanf("%d", &pizza_type);

	printf("Please write how many slices you want? : \n");
	scanf("%d", &slice);

	double total_area;

	if (pizza_type == 1)
		total_area = ((20 * 20 * pi) / 6.0) * slice;
	else if (pizza_type == 2)
		total_area = ((16 * 16 * pi) / 6.0) * slice;
	else
		total_area = ((12 * 12 * pi) / 6.0) * slice;

	double calori = (total_area)*0.75;

	if (calori >= 700.0)
		printf("You eat %.2lf calori. It is enough for today! \n", calori);
	else if (calori <= 300.0)
		printf("You eat %.2lf calori. What a healthy body.. \n", calori);
	else
		printf("You eat %.2lf calori. Do not make it habit. \n", calori);

	return 0;
}