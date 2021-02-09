#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double get_angle(int hour, int minute)
{
    double angle;
    angle = fabs(((12 - hour) * 30)) - (6 * minute);
    return fabs(angle);
}

int main()
{
    int h, m;
    printf("Hour and minute: \n");
    scanf("%d %d", &h, &m);
    double angle;
    angle = get_angle(h, m);
    printf("the angle between hour-hand and minute-hand is : %f\n", angle);
}
