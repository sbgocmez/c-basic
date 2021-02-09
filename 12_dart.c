#include <stdio.h>
#include <stdlib.h>
// thats an assignment for school, and game has some spesific rules.

int remain_along_the_game(int remain, int points, char k)
{
	if ((remain > (points + 1)) || (remain == points && k == 'D'))
	{
		remain = remain - points;
	}
	return remain;
}

int point_value_for_throw(int number, char c)
{
	int point_value = 0;
	if (c == 'S')
	{
		point_value = number;
	}
	else if (c == 'D')
	{
		point_value = number * 2;
	}
	else if (c == 'T')
	{
		point_value = number * 3;
	}
	else if (c == 'I')
	{
		point_value = 50;
	}
	else if (c == 'O')
	{
		point_value = 25;
	}
	return point_value;
}

int main()
{
	int target = 0;
	int segment = 0;
	char i;
	printf("Target: ");
	scanf("%d", &target);
	printf("Throw: ");
	scanf("%d %c", &segment, &i);

	while (i != 'D')
	{
		printf("Points: %d\n", target);
		printf("Throw: ");
		scanf("%d %c", &segment, &i);
	}
	int points_value = point_value_for_throw(segment, i);
	int current_point = remain_along_the_game(target, points_value, i);

	while (current_point != 0)
	{
		printf("Points: %d\n", current_point);
		printf("Throw: ");
		scanf("%d %c", &segment, &i);
		points_value = point_value_for_throw(segment, i);
		current_point = remain_along_the_game(current_point, points_value, i);
	}
	printf("Points: %d\n", current_point);
	return EXIT_SUCCESS;
}