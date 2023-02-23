#include <stdio.h>

int main()
{
    int sec;
    printf("Input seconds sec: ");
    scanf("%d", &sec);
    int hours = sec / 3600;
    sec = sec - hours * 3600;
    int minutes = sec / 60;
    sec = sec % 60;

    printf("Hours: %d , minutes: %d , seconds: %d ", hours, minutes, sec);

    return 0;
}
