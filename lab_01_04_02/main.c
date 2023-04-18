#include <stdio.h>
#define HOUR_SEC 3600
#define MINUTE_SEC 60

int calc_hours(int sec);

int calc_minutes(int sec, int hours);

int calc_sec(int sec);

int main()
{
    int sec = 0;
    printf("Input seconds sec: ");
    scanf("%d", &sec);
    int hours = calc_hours(sec);
    int minutes = calc_minutes(sec, hours);
    sec = calc_sec(sec);

    printf("Hours: %d , minutes: %d , seconds: %d ", hours, minutes, sec);

    return 0;
}

int calc_hours(int sec)
{
    int hours = sec / HOUR_SEC;
    return hours;
}

int calc_minutes(int sec, int hours)
{
    int minutes = sec % HOUR_SEC / MINUTE_SEC;
    return minutes;
}

int calc_sec(int sec)
{
    int second = sec % MINUTE_SEC;
    return second;
}