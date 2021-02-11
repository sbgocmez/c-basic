#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int hour;
	int min;
	int sec;
} CLOCK;

void increment(CLOCK *clock)
{
	clock->sec++;

	if (clock->sec == 60)
	{
		clock->sec = 0;
		clock->min++;
	}

	if (clock->min == 60)
	{
		clock->min = 0;
		clock->hour++;
	}

	if (clock->hour == 24)
	{
		clock->hour = 0;
	}
}
void show(CLOCK *clock)
{
	printf("%02d:%02d:%02d\n", clock->hour, clock->min, clock->sec);
}

int main()
{
	CLOCK clock = {14, 38, 56};
	int k, t;
	printf("How many seconds? ");
	scanf("%d", &t);
	for (k = 0; k < t; k++)
	{
		increment(&clock);
		show(&clock);
	}

	return EXIT_SUCCESS;
	;
}
