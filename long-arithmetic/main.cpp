#include <iostream>
#include "LongNumber.h"

using namespace std;

int main()
{
    /*LongNumber number1("11111",10);

    LongNumber number2("22", 10);

    cout<<"("<<number1<<" > "<<number2<<") ? "<<(number1 > number2)<<endl;
    cout<<"("<<number1<<" < "<<number2<<") ? "<<(number1 < number2)<<endl;

    cout<<"number1 = "<<number1<<endl;
    cout<<"number2 = "<<number2<<endl;
    cout<<endl;
    number1 = number2;
    cout<<"number1 = "<<number1<<endl;
    cout<<"number2 = "<<number2<<endl;*/

    /**LongNumber n1;
    LongNumber n2;
    LongNumber n3("2468",10);
    LongNumber n4;
    cout<<n3<<endl;

    n4 = n1 = n2 = n3;
    cout<<n2<<endl;
    cout<<n1<<endl;
    cout<<n4<<endl;*/

    /*LongNumber l1("-123456",10);
    LongNumber l2 = l1;
    LongNumber l3;
    LongNumber l4("124",3);

    l4 = l3 = l2;

    cout<<l1<<endl;
    cout<<l2<<endl;
    cout<<l3<<endl;
    cout<<l4<<endl;*/

    LongNumber n1("223", 10);
    LongNumber n2("222", 10);
    cout<<n1<<" < "<<n2<<" ("<<(n1 < n2)<<")"<<endl;
    cout<<n1<<" > "<<n2<<" ("<<(n1 > n2)<<")"<<endl;


    /*char a = '1';
    char b = '5';

    int r = ('2'-'0')+('4'-'0');
    char q = r+'0';
    cout<<"rez = "<<q;*/

    /*int a = 5;
    int b = 2;

    int rez = a+b;

    char q = (rez)+'0';

    cout<<endl<<"char = "<<q;*/



    return 0;
}

















