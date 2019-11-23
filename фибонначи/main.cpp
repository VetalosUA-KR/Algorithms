#include <iostream>

using namespace std;

int fib(int a)
{
    if(a <= 1)
    {
        return 1;
    }
    else
    {
        return fib(a-2)+fib(a-1);
    }
}

void fibN(int n)
{
    int sum = 0;
    int l1 = 1;
    int l2 = 1;
    for(int i = 2; i <= n; i++)
    {
        sum = l1+l2;
        l1 = l2;
        l2 = sum;
    }
    cout<<sum<<endl;
}

int factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}

int main ()
{

    cout<<fib(8)<<endl;
    fibN(8);

    return 0;
}
