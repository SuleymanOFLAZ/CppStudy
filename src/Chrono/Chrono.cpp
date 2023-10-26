/* 
This drill simply involves getting the sequence of versions of Date to work. 
For each version define a Date called today initialized to June 25, 1978. 
Then, define a Date called tomorrow and give it a value by copying today into 
it and increasing its day by one using add_day(). Finally, output today and 
tomorrow using a << defined as in §9.8.
Your check for a valid date may be very simple. 
Feel free to ignore leap years. However, don’t accept a month that is not in 
the [1,12] range or day of the month that is not in the [1,31] range. Test each 
version with at least one invalid date (e.g., 2004, 13, –5). 
    1. The version from §9.4.1 
    2. The version from §9.4.2 
    3. The version from §9.4.3 
    4. The version from §9.7.1 
    5. The version from §9.7.4
*/
#include <iostream>
#include "Chrono.h"

using namespace std;

// Version from 9.4.2

struct Date{
    int y, m , d;
    class Invalid{};
    Date(int y, int m, int d);
    void add_day(int n);
};

bool is_date_valid(int y, int m, int d)
{
    if( (d < 1 || 31 < d) || (m < 1 || 12 < m) )
    {
        return false;
    }

    return true;   
}

Date::Date(int yy, int mm, int dd)
     : y{yy}, m {mm}, d{dd}
{
    if(!is_date_valid(y, m, d)) throw Invalid{};
}

void Date::add_day(int n)
{
    int yy = 0, mm = 0, dd = 0;
    yy = n / 365;
    n -= yy*365;

    mm = n / 31;
    n -= mm*31;
    dd = n ;

    if ( (d+dd) > 31 )
    {
        mm++;
        dd = (d+dd) % 31;
        d = 0;
    }

    if ( (m+mm) > 12 )
    {
        yy++;
        mm = (m+mm) % 12; 
        m = 0;
    }

    y += yy;
    m += mm;
    d += dd;
}

ostream& operator<<(ostream& os, Date& dd)
{
    return os << '(' << dd.y << ',' << dd.m << ',' << dd.d << ')' << '\n';
}

void error(int en)
{
    cout << "Error No: " << en << endl; 
}

int main(void)
{
    Date* date_Ptr;
    try {
        date_Ptr = new Date {1978, 6, 25};
    }
    catch (Date::Invalid){
        error(1);
    }

    cout << *date_Ptr;

    Date tomorrow = *date_Ptr;
    tomorrow.add_day(1);

    cout << tomorrow;

    Date* date_Ptr2;
    try {
        date_Ptr2 = new Date  {1997, -7, 22};
    }
    catch (Date::Invalid){
        error(1);
    }

    return 0;
}