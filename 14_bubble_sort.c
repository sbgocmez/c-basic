#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// bubble sort array
int main()
{
	int data[MAX] = {2, 7, 3, 1, 4, 6, 8, 5, 9, 0};
	int temp = data[0];
	printf("\n      : original array is :\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("%4d", data[i]);
	}
	printf("\n      Ascending started...\n\n******************\n");
	for (int i = 0; i < MAX; i++)
	{
		for (int j = i; j < MAX; j++)
		{
			if (data[i] > data[j])
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		printf("%4d", data[i]);
	}
	printf("\n      Descending started...\n\n******************\n");
	for (int i = 0; i < MAX; i++)
	{
		for (int j = i; j < MAX; j++)
		{
			if (data[i] < data[j])
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		printf("%4d", data[i]);
	}
	printf("\n******************\n        Descending finished...\n\n******************\n");
	return EXIT_SUCCESS;
}