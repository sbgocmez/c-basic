#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

//manhattan distance function
int manhattan_distance(int y_empty, int x_empty, int filled_y, int filled_x)
{
	int total_distance = 0;
	int y_distance = y_empty - filled_y;
	int x_distance = x_empty - filled_x;
	if (y_distance < 0)
	{
		y_distance *= -1;
	}
	if (x_distance < 0)
	{
		x_distance *= -1;
	}
	total_distance = y_distance + x_distance;
	return total_distance;
}
// fill with 0
void fill_zero(int data[][MAX_SIZE], int size)
{
	for (int i = 1; i <= size; i++)
	{
		for (int k = 1; k <= size; k++)
		{
			data[i][k] = 0;
		}
	}
}
int main()
{
	//declare an array
	int cars_array[MAX_SIZE][MAX_SIZE];
	//get size from user
	int current_size = 0;
	//get size and check if valid or not
	printf("Size: ");
	scanf("%d", &current_size);
	while (current_size > MAX_SIZE || current_size < 1)
	{
		printf("Size must be between 50 and 1\n");
		printf("Size: ");
		scanf("%d", &current_size);
	}
	//fill all the parks 0 [empty]
	fill_zero(cars_array, current_size);
	//get number of cars and error checking
	int number_of_cars = 0;
	printf("Cars: ");
	scanf("%d", &number_of_cars);
	if (number_of_cars == 0)
	{
		printf("Best Slot Found In: 1 1\n");
	}
	else if (number_of_cars == (current_size * current_size))
	{
		printf("Best Slot Found In: 0 0\n");
	}
	//program for valid ones
	else
	{
		//get cars x-y coordinates
		int count = 0, coordinate_x = 0, coordinate_y = 0;
		//int m_distance = 0;
		while (count < number_of_cars)
		{
			printf("Locations: ");
			scanf("%d %d", &coordinate_x, &coordinate_y);
			cars_array[coordinate_y][coordinate_x] = 1;
			count++;
		}
		//call manhattan distance calculator function
		int distance_array[MAX_SIZE][MAX_SIZE];
		//fill al the distances as 0.
		fill_zero(distance_array, current_size);

		for (int empty_y = 1; empty_y <= current_size; empty_y++)
		{
			for (int empty_x = 1; empty_x <= current_size; empty_x++)
			{
				if (cars_array[empty_y][empty_x] == 0)
				{
					int distance = 0;
					for (int y = 1; y <= current_size; y++)
					{
						for (int x = 1; x <= current_size; x++)
						{
							if (cars_array[y][x] == 1)
							{
								distance += manhattan_distance(empty_y, empty_x, y, x);
							}
						}
					}
					distance_array[empty_y][empty_x] = distance;
				}
			}
		}

		int largest_distance = 0, previous_a = 0, previous_b = 0;
		for (int a = 1; a < (current_size + 1); a++)
		{
			for (int b = 1; b < (current_size + 1); b++)
			{
				//if (cars_array[a][b] = 1) {
				if (distance_array[a][b] > largest_distance && cars_array[a][b] == 0)
				{
					largest_distance = distance_array[a][b];
					previous_a = a;
					previous_b = b;
				}
				else if (distance_array[a][b] == largest_distance && distance_array > 0 && cars_array[a][b] == 0)
				{
					if (b < previous_b)
					{
						previous_b = b;
						previous_a = a;
					}
					else if (b == previous_b && a < previous_a)
					{
						previous_a = a;
						previous_b = b;
					}
				}
				//}
			}
		}

		printf("Best Slot Found In: %d %d\n", previous_b, previous_a);
	}

	return EXIT_SUCCESS;
}