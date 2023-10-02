/*
=== The Great Calendar Crisis ===
=== The Great Solar System Crisis ===
Discovered that September 1752 had 11
entire days missing from the calendar 💀
=================================
*/

#include <stdio.h>
#include <stdlib.h>

// Function to Repeat Specific Patterns Using Character Repition

void repeatChar(char character, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%c", character);
    }
}

int isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0 && year > 1799)
        {
            if (year % 400 == 0)
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
    else
    {
        return 0;
    }
}

int getNumberOfDaysInMonth(int month, int year)
{
    int numberOfDays;
    month = month - 12 * (year - 1);

    if (year == 1752 && month == 9)
    {
        return 19;
    }

    if (month <= 7)
    {
        if (month % 2 == 0)
        {
            if (month == 2)
                numberOfDays = isLeapYear(year) ? 29 : 28;
            else
                numberOfDays = 30;
        }
        else
        {
            numberOfDays = 31;
        }
    }
    else
    {
        if (month % 2 == 0)
            numberOfDays = 31;
        else
            numberOfDays = 30;
    }
    return numberOfDays;
}

// Function to get the Starting Day of a Month(i.e. Mon, Tue)
int getfirstDayOfMonth(int month, int year)
{
    int totalNumberOfDays = 6;
    for (int temp_month = 1, temp_year = 1; temp_month < ((year - 1) * 12) + month; temp_month++)
    {
        totalNumberOfDays += getNumberOfDaysInMonth(temp_month, temp_year);
        if (temp_month % 12 == 0)
            temp_year++;
    }

    return (totalNumberOfDays % 7);
}

// Function to Generate the Calendar
void drawCal(int date, int month, int year)
{
    int numberOfDays = getNumberOfDaysInMonth(month + (year - 1) * 12, year), firstDayOfMonth = getfirstDayOfMonth(month, year);

    printf("Su Mo Tu We Th Fr Sa\n");
    repeatChar(' ', firstDayOfMonth * 3);

    for (int currentDate = 1, currentDay = firstDayOfMonth; currentDate <= numberOfDays; currentDate++)
    {
        if (currentDate < 10)
            printf("0");
        printf("%d ", currentDate);
        if (currentDay == 6)
        {
            printf("\n");
            currentDay = 0;
            continue;
        }
        currentDay++;
    }
    printf("\n");
}

int main()
{
    // Declarations
    int day, month, year;

    // Getting The Values
    printf("Enter the Date: ");
    scanf("%d", &day);
    printf("Enter the Month: ");
    scanf("%d", &month);
    printf("Enter the Year: ");
    scanf("%d", &year);

    drawCal(day, month, year);

    return 0;
}