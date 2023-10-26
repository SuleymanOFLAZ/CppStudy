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

// Version from 9.4.1

struct Date{
    int y;
    int m;
    int d;
};

bool init_day(Date& dd, int y, int m, int d)
{
    if( (d < 1 || 31 < d) || (m < 1 || 12 < m) )
    {
        return false;
    }

    dd.y = y;
    dd.m = m;
    dd.d = d;

    return true;
}

void add_day(Date& dd, int n)
{
    int y = 0, m = 0, d = 0;
    y = n / 365;
    n -= y*365;

    m = n / 31;
    n -= m*31;
    d = n ;

    if ( (dd.d+d) > 31 )
    {
        m++;
        d = (dd.d+d) % 31;
        dd.d = 0;
    }

    if ( (dd.m+m) > 12 )
    {
        y++;
        m = (dd.m+m) % 12; 
        dd.m = 0;
    }

    dd.y += y;
    dd.m += m;
    dd.d += d;
}

ostream& operator<<(ostream& os, Date& dd)
{
    return os << '(' << dd.y << ',' << dd.m << ',' << dd.d << ')' << '\n';
}

int main(void)
{
    Date today;
    init_day(today, 1978, 6, 25);

    cout << today;

    Date tomorrow = today;
    add_day(tomorrow, 1);

    cout << tomorrow;

    bool success = init_day(today, 1978, 6, -25);
    if(success == false){
        cout << "Initialize Error\n";

    }

    return 0;
}