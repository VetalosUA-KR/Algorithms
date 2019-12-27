#include <iostream>
#include "LongNumber.h"

using namespace std;

int main()
{

    LongNumber n1("-10",10);
    LongNumber n2("-100", 10);
    //cout<<n1<<" > "<<n2<<"  ==  "<<(n1 > n2)<<endl;
    //cout<<n1<<" < "<<n2<<"  ==  "<<(n1 < n2)<<endl;
    LongNumber n3;
    //cout<<"n3 = "<<n3<<endl;

    cout<<"n1 = "<<n1<<endl;
    cout<<"n2 = "<<n2<<endl;

    cout<<n1<<" - "<<n2<<" = "; n3 = n1 - n2; cout<<"otvet = "<<n3<<endl;

    cout<<"n1 = "<<n1<<endl;
    cout<<"n2 = "<<n2<<endl;

    return 0;
}
