#include <stdio.h>
#include <stdlib.h>

int main() //задача 4 вариант 2
{
    int sec;
    printf("Input seconds sec: ");
    scanf("%d", &sec);
    int hours = sec / 3600;
    sec = sec - hours * 3600;
    int minutes = sec / 60;
    sec = sec % 60;

    printf("Hours: %d, minutes: %d, seconds: %d", hours, minutes, sec);

    return 0;
}
