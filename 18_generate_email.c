#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 50

/*
    Name: Sarah
    Surname: Jones
    Year: 1983

    candidate1 = sjones83@boomy.com
    candidate2 = sajo3829@boomy.com // random number
    candidate3 = sarahjones1983@boomy.com
*/

void swap(char *ch1, char *ch2)
{
    char temp;
    temp = *ch2;
    *ch2 = *ch1;
    *ch1 = temp;
}

// it takes the begining address of the array and returns the size of the array.
// the size of the array = the length of the string. 'n', 'e'
int my_strlen(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++)
        ;
    return i;
}

char *my_itoa(int val, char *str) // 123 -> "123"
{
    int len;
    int i = 0;
    len = my_strlen(str);

    do
        str[i++] = (val % 10) + '0';
    while ((val /= 10) > 0);
    str[i] = '\0';

    if (len == 1) // first candidate case
        swap(&str[0], &str[1]);
    else
    {
        for (i = 0; i < len / 2; i++)
            swap(&str[i], &str[len - 1 - i]);
    }
    return str;
}

char *substr(char *dest, char *source, int begin, int n)
{
    int len = my_strlen(source);
    int i;

    if (begin + n <= len)
    {
        source += begin;

        for (i = 0; i < n; i++)
            dest[i] = source[i];

        dest[i] = '\0';
    }

    return dest;
}

char *my_strcpy(char *dest, char *source) // ""+gunes=gunes
{
    int len = my_strlen(source);
    int i;

    for (i = 0; i < len + 1; i++)
        dest[i] = source[i];

    return dest;
}

char *my_strcat(char *dest, char *source) // nese+gunes = nesegunes
{
    int len = my_strlen(dest);
    // after this operation, we're now at the end of the string.
    dest += len;

    return my_strcpy(dest, source);
}

void generateEmail(char *name, char *surname, int year)
{
    char candidate1[MAX_STRING_LENGTH] = "";
    char candidate2[MAX_STRING_LENGTH] = "";
    char candidate3[MAX_STRING_LENGTH] = "";
    char ending[MAX_STRING_LENGTH] = "@boomy.com";
    // for storing temporary strings we have dest.
    char dest[MAX_STRING_LENGTH] = "";

    // Get the 1 char of the name
    my_strcat(candidate1, substr(dest, name, 0, 1)); // candidate <- "n"
    my_strcat(candidate1, surname);

    // Concatanate with the last two digits of the year.
    if (year % 100 < 10)
        my_strcat(candidate1, my_itoa((year % 100), dest));
    else
        my_strcat(candidate1, my_itoa((year % 100), dest));

    // Concatanate the ending "@itu.edu.tr"
    my_strcat(candidate1, ending);

    my_strcat(candidate2, substr(dest, name, 0, 2));
    my_strcat(candidate2, substr(dest, surname, 0, 2));
    my_strcat(candidate2, my_itoa((1000 + rand() % 9000), dest));
    my_strcat(candidate2, ending);

    my_strcat(candidate3, name);
    my_strcat(candidate3, surname);
    my_strcat(candidate3, my_itoa(year, dest));
    my_strcat(candidate3, ending);

    // print the candidate e-mails.
    printf("E-mail candidate 1: %s \n", &candidate1[0]); // %s shows: *ptr, it takes ptr
    printf("E-mail candidate 2: %s \n", candidate2);
    printf("E-mail candidate 3: %s \n", candidate3);

    return;
}

int main()
{
    srand(time(NULL));

    char name[MAX_STRING_LENGTH];
    char surname[MAX_STRING_LENGTH];
    int year;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your surname: ");
    scanf("%s", surname);

    printf("Enter your birth-day: ");
    scanf("%d", &year);

    generateEmail(name, surname, year);

    return 0;
}
