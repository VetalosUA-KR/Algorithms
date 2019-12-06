#include <iostream>
#include "LongNumber.h"

using namespace std;

int main()
{
    LongNumber number1("10",10);

    LongNumber number2("-20", 10);

    cout<<(number1 < number2)<<endl;
    cout<<(number1 > number2)<<endl;
    cout<<number1<<endl;
    cout<<number2<<endl;
    return 0;
}
