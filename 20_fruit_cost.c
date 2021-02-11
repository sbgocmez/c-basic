#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
	N: number of prices on the stall. we dont know which price stand for which fruit
	M: total number of fruit kilos.
	
	Calculate minimum and maximum total cost for given (user input) fruits.
*/

typedef struct
{
	char name[20];
	int kg;
} FRUIT;

int main()
{
	int N = -5, M = -5;
	while (N < 10 || N >= 100 || M < 3 || M >= 10)
	{
		printf("Proper N and M (N is between 10-100 and M is between 3 and 10): ");
		scanf("%d %d", &N, &M);
	}

	int *data = (int *)malloc(N * sizeof(int));
	srand(time(NULL));
	int n = 0;
	printf("Here are the randomized prices: \n");
	while (n < N)
	{
		*(data + n) = rand() % 11;
		if (*(data + n) != 0)
		{
			printf("%d - ", *(data + n));
			n++;
		}
	}
	int temp = 0;
	for (int k = 0; k < N; k++)
	{
		for (int j = k + 1; j < N; j++)
		{
			if (*(data + k) < *(data + j))
			{
				temp = *(data + k);
				*(data + k) = *(data + j);
				*(data + j) = temp;
			}
		}
	}

	FRUIT fp[10];

	printf("\nName of the fruits: \n");
	for (int i = 0; i < M; i++)
		scanf("%s", fp[i].name);

	for (int i = 0; i < M; i++)
		fp[i].kg = 1;

	for (int i = 0; i < M; i++)
	{
		for (int k = i; k < M; k++)
		{

			if ((strcmp(fp[i].name, fp[k].name) == 0) && (fp[i].kg != 0) && (i != k))
			{
				fp[i].kg++;
				fp[k].kg = 0;
			}
		}
	}

	for (int k = 0; k < M; k++)
	{
		for (int j = k + 1; j < M; j++)
		{
			if (fp[k].kg < fp[j].kg)
			{
				temp = fp[k].kg;
				fp[k].kg = fp[j].kg;
				fp[j].kg = temp;
			}
		}
	}

	int total_max = 0;
	int total_min = 0;

	for (int y = 0; y < M; y++)
	{
		total_min = total_min + fp[y].kg * data[N - y - 1];
		total_max = total_max + fp[y].kg * data[y];
	}
	printf("\n");
	printf("Total max: %d\n", total_max);
	printf("Total min: %d\n", total_min);

	free(data);
	return 0;
}