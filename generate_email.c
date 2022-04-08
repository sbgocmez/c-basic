#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 50

void swap(char *ch1, char *ch2)
{
    char temp;

    temp = *ch2;
    *ch2 = *ch1;
    *ch1 = temp;
}

char *my_itoa(int val, char *str) // 123 -> "123"
{
    int len;
    int i = 0;
    
    // 1st iter: str[0] = 3
    // 2nd iter: str[1] = 2
    // 3rd iter: str[2] = 1
    do {
        // ++i ----> i = i + 1, we use (i + 1) and it is (i + 1)
        // i++ ----> is i and then it is increased by one, and becomes i+1
        str[i++] = (val % 10) + '0';
        
        // int i = 5;
        // double d = i + 0.0;
        // i++;
    } while((val /= 10) > 0);
    
    str[i] = '\0';
    
    for (i = 0; i < len/2; i++)
        swap(&str[i], &str[len - 1 - i]);

    return str;
}

// it takes the begining address of the array and returns the size of the array.
// the size of the array = the length of the string. 'n', 'e'
int my_strlen(char *str)
{
    int i = 0;
    
    // NULL character:         '\0'
    // whitespace character:   ' '
    for (; str[i] != '\0'; i++)
        ;
    
    // for (int i = 0; str[i] != '\0'; i++);
    
    return i;
}

char *substr(char *dest, char *source, int begin, int n)
{
    int len = my_strlen(source);
    int i;
    
    if (begin + n <= len) {
        // ptr = ptr + begining_index
        // ptr++
        // ptr = ptr + 1
        // ptr = ptr + 3
        // ptr = ptr + begin_index
        // ptr += begin
        source += begin; // nesefhdkjg it was pointing n, now it points s
        
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
    char ending[MAX_STRING_LENGTH] = "@itu.edu.tr";
    // for storing temporary strings we have dest.
    char dest[MAX_STRING_LENGTH] = "";
    
    // Get the 1 char of the name
    my_strcat(candidate1, substr(dest, name, 0, 1)); // candidate <- "n"
    
    // Concatanate the first char with the surname
    my_strcat(candidate1, surname);
    
    // Concatanate with the last two digits of the year.
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
    // two following lines are interpreted as the same by the compiler.
    scanf("%s", name);
    // scanf("%s", name);
    
    printf("Enter your surname: ");
    scanf("%s", surname);
    
    printf("Enter your birth-day: ");
    scanf("%d", &year);

    generateEmail(name, surname, year);
    
    return 0;
}
