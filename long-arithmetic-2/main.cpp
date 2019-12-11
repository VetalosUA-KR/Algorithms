#include <iostream>
#include "LongNumber.h"

using namespace std;

int main()
{

    LongNumber n1("-193",10);
    LongNumber n2("4", 10);
    //cout<<n1<<" > "<<n2<<"  ==  "<<(n1 > n2)<<endl;
    //cout<<n1<<" < "<<n2<<"  ==  "<<(n1 < n2)<<endl;

    cout<<n1<<" + "<<n2<<" = ";n1 + n2;

    return 0;
}
