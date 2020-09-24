//BETUL CAM
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int zeller(int year, int m, int q){ // it is applying zeller formula
    if (m == 1 || m == 2){
        year--;
        m += 12;
    }
    int j = year / 100;
    int k = year % 100;
    return (q + 13*(m + 1)/5 + k + k/4 + j/4 + 5*j) % 7;
}
int how_many_times(int starting_year, int end_year, int month, int day){ //calculates how many times it falls on the same day between given dates
    int x = zeller(starting_year, month, day), result = 0;
    for (int i = starting_year + 1; i <= end_year; i++)
    {
        if(zeller(i, month, day) == x) result++;
    }
    return result;
}
bool is_valid(int year, int month, int day){ // it checks if input is valid or not
    if(year%4 != 0 && month == 2 && day>28 ) return false;
    if(year%4 == 0 && month == 2 && day > 29) return false;
    if (month < 0) return false;
    if (month > 12) return false;
    if (day < 0) return false;
    if (day > 31) return false;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day <= 31) return true;
    }
    else if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11){
        if (day <= 30) return true;
    }
    return false;;
}

int main(){
    int year, month, day, end_year;
    printf("Enter date [year month day]: ");
    scanf("%d %d %d", &year, &month, &day);
    if(is_valid(year, month, day) == false){
        printf("Invalid date.\n");
        return EXIT_FAILURE;
    }
    printf("Enter end year: ");
    scanf("%d", &end_year);
    if(end_year <= 0){
        printf("Invalid date.\n");
        return EXIT_FAILURE;
    }
    int x = zeller(year, month, day);

    if(x == 0) printf("It's a Saturday.\n");
    else if(x == 1) printf("It's a Sunday.\n");
    else if(x == 2) printf("It's a Monday.\n");
    else if(x == 3) printf("It's a Tuesday.\n");
    else if(x == 4) printf("It's a Wednesday.\n");
    else if(x == 5) printf("It's a Thursday.\n");
    else if(x == 6) printf("It's a Friday.\n");


    int how_many_t = how_many_times(year, end_year, month, day);
    printf("Same day-and-month on same weekday between %d and %d: %d\n", year+1, end_year, how_many_t);
    return EXIT_SUCCESS;
}