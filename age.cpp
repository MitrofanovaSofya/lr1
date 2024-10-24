#include "age.h"

int calculateAge(int birthDay, int birthMonth, int birthYear,int deathDay, int deathMonth, int deathYear) {
    int age;
    if (deathYear == 0) {
        time_t t = time(0); 
        tm* now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        int currentMonth = now->tm_mon + 1;
        int currentDay = now->tm_mday;

        age = currentYear - birthYear;
        if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
            age--;
        }
    }
    else {
        age = deathYear - birthYear;
        if (deathMonth < birthMonth || (deathMonth == birthMonth && deathDay < birthDay)) {
            age--;
        }
    }
    return age;
}
