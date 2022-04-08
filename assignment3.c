#include <stdio.h> 
#include <stdlib.h>

#define MAX 50

/**
*
*/
void find_best_slot(int parking_area[][MAX], int park_size, int distance_ar[][MAX])
{
	int distance = 0;
	int largest_distance = 0;
	int smallest_distance = 100;
	//int best_slot = 0;
	int best_x = 0, best_y = 0;
	
	for(int y_empty = 0; y_empty < park_size; y_empty++){
		for(int x_empty = 0; x_empty < park_size; x_empty++){
			if(parking_area[y_empty][x_empty] == 0){
				for(int y_filled = 0; y_filled < park_size; y_filled++){
					for(int x_filled = 0; x_filled < park_size; x_filled++){
						if(parking_area[y_filled][x_filled] == 1){
							distance_ar[y_empty][x_empty] = abs(x_filled - x_empty) + abs(y_filled - y_empty);
							if(distance_ar[y_empty][x_empty] < smallest_distance){
								smallest_distance = distance_ar[y_empty][x_empty];
							}
						}
					}
				}
				//largest_distance = smallest_distance;
				if(largest_distance == 0 || smallest_distance > largest_distance){
					largest_distance = smallest_distance;
					best_x = x_empty;
					best_y = y_empty;
					//best_slot = (100 * (best_x + 1)) + (best_y + 1);
				}
				
			}
			
		}
	}
	printf("Best Slot Found In: %d %d\n", best_x, best_y);
	
}

int main()
{
	int park_size = 0;
	printf("Size: ");
	scanf("%d", &park_size);
	
		while(park_size > 50 || park_size < 1){
			printf("Size must be between 50 and 1\n");
			printf("Size: ");
			scanf("%d", &park_size);
		}
	
	
	const int PARK_SIZE = park_size;
	int parking_area[PARK_SIZE][PARK_SIZE];
	for(int j = 0; j < PARK_SIZE; j++){
		for(int i = 0; i < PARK_SIZE; i++){
			parking_area[j][i] = 0;
		}
	}
	
	int parked_cars;
	printf("Cars: ");
	scanf("%d", &parked_cars);
	
	int x_user, y_user;
	for(int number = 0; number < parked_cars; number++){
		printf("Location: ");
		scanf("%d %d", &x_user, &y_user);
		if (x_user - 1 <= park_size && y_user - 1 <= park_size){
			parking_area[y_user - 1][x_user - 1] = 1;
		}
	}
	
	//int best_slot;
	//int best_x, best_y;
	if(parked_cars >= park_size * park_size) {
		printf("Best Slot Found In: 0 0\n");
	}
	else if(parked_cars == 0){
		printf("Best Slot Found In: 1 1\n");
	}
	else{
		int data[PARK_SIZE][PARK_SIZE];
		for(int j = 0; j < PARK_SIZE; j++){
		for(int i = 0; i < PARK_SIZE; i++){
			data[j][i] = 0;
		}
	}
		
		find_best_slot(parking_area, park_size, data);
		//best_x = best_slot / 100;
		//best_y = best_slot - (best_x * 100);
		//printf("Best Slot Found In: %d %d\n", best_x, best_y);
	}
	
	//printf("Best Slot Found In: %d %d\n", best_x, best_y);
	
	return 0;
}
