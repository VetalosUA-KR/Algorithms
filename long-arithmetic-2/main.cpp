#include <iostream>
#include "LongNumber.h"

using namespace std;

int main()
{

    LongNumber n1("150",10);
    LongNumber n2("999", 10);
    LongNumber n4("15", 10);

    LongNumber rez = n1+n2;
    cout<<n1<<" + "<<n2<<" = "<<rez<<endl;

    rez = n1 - n2;
    cout<<n1<<" - "<<n2<<" = "<<rez<<endl;

    rez = n1 * n2;
    cout<<n1<<" * "<<n2<<" = "<<rez<<endl;

    rez = n1 / n4;
    cout<<n1<<" / "<<n4<<" = "<<rez<<endl;



    return 0;
}
