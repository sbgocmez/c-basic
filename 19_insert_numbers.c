#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
	int array[SIZE];
	int current_size = 0;
	printf("How many numbers?: "); scanf("%d", &current_size);
	//get the numbers
	printf("numbers: ");
	int i = 0;
	while (i != current_size) {
		scanf("%d", &array[i]);
		i++;
	}
	//print the array
	for (int i = 0; i < current_size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	//get the new number and its position
	int new_number = 0, position = 0;
	current_size++;
	printf("new number and its position: "); scanf("%d %d", &new_number, &position);
	//locate it
	for (int i = current_size-1; i > position; i--) {
		array[i] = array[i-1];
	}
	//print new array
	array[position] = new_number;
	for (int i = 0; i < current_size; i++) {
		printf("%d ", array[i]);
	}
	
	return EXIT_SUCCESS;
}