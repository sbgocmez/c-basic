#include <stdio.h>	 //printf-scanf
#include <stdlib.h>	 //return success-failure
#include <stdbool.h> //assign a boolean for invalid/valid.

// this was an school assignment
int main()
{
	int init_day = 0;
	int init_month = 0;
	int init_year = 0;
	bool notValid;
	//get a date from the user.
	printf("Enter date [year month day]: ");
	scanf("%d %d %d", &init_year, &init_month, &init_day);

	int four_divide = init_year % 4; //this is just important for feb29. but before the subtraction. on original year!
	//determine the date is valid or not.
	if (init_year <= 0)
	{
		notValid = true; //hope its ok for any > 0. tried 9999 then 10000, it looks ok. and then also.
	}
	else if (init_day > 31 || init_day <= 0)
	{
		notValid = true;
	}
	else if (init_month <= 0 || init_month > 12)
	{
		notValid = true;
	}
	else if (init_month < 3)
	{
		if (init_month == 2)
		{
			if (init_day == 29 && four_divide != 0)
			{
				notValid = true;
			}
			else if (init_day > 29)
			{
				notValid = true;
			}
			else
			{
				init_month += 12;
				init_year--;
			}
		}
		else if (init_month == 1)
		{
			init_month += 12;
			init_year--;
		}
	}
	else if (init_day == 31)
	{
		switch (init_month)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			notValid = true;
			break;
		}
	}
	//for invalid ones, print and end with failure code.
	if (notValid)
	{ //instead of else if, IF !!
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	//for valid ones, go on.

	int q = init_day;
	int m = init_month;
	int j = init_year / 100;
	int k = init_year % 100;
	//zeller's congruence
	int init_weekday = (q + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) + 5 * j) % 7;
	//get end year from the user.
	int end_year = 0;
	printf("Enter end year: ");
	scanf("%d", &end_year);
	//determine and print the weekday the date' corresponds to.
	switch (init_weekday)
	{
	case 0:
		printf("It's a Saturday.\n");
		break;
	case 1:
		printf("It's a Sunday.\n");
		break;
	case 2:
		printf("It's a Monday.\n");
		break;
	case 3:
		printf("It's a Tuesday.\n");
		break;
	case 4:
		printf("It's a Wednesday.\n");
		break;
	case 5:
		printf("It's a Thursday.\n");
		break;
	case 6:
		printf("It's a Friday.\n");
		break;
	}
	//to count same day-and-month on same weekday between [initial date's year++ and end year].
	int count = 0;

	if (init_month < 13)
	{
		init_year++;
		int year = init_year;
		while (year <= end_year)
		{
			for (int month = init_month; month <= init_month; month++)
			{
				for (int day = init_day; day <= init_day; day++)
				{
					q = day;
					m = month;
					j = year / 100;
					k = year % 100;
					int weekday = (q + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) + 5 * j) % 7;
					if (weekday == init_weekday)
					{
						count++;
					} //want to initialize and update at same line, this why for loops look like ineffective.
				}
			}
			year++;
		}
		printf("Same day-and-month on same weekday between %d and %d: %d\n", init_year, end_year, count);
	}
	else
	{
		init_year++; //this makes init_year == initial date's year, before we substract now add. it will count because of Jan and Feb.
		int year = init_year;
		end_year--; //end year's 1st and 2nd months = --end year's 13 and 14th months.
		while (year <= end_year)
		{
			four_divide = (year + 1) % 4;
			if ((four_divide != 0) && (init_day == 29) && (init_month == 14))
			{ //şubat detayını ekle!!
				;
			}
			else
			{
				for (int month = init_month; month <= init_month; month++)
				{
					for (int day = init_day; day <= init_day; day++)
					{
						q = day;
						m = month;
						j = year / 100;
						k = year % 100;
						int weekday = (q + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) + 5 * j) % 7;
						if (weekday == init_weekday)
						{
							count++;
						}
					}
				}
			}
			year++;
		}
		init_year++; //we make years correct to print, because user doesnt now what we did in program.
		end_year++;
		printf("Same day-and-month on same weekday between %d and %d: %d\n", init_year, end_year, count);
	}
	return EXIT_SUCCESS;
}