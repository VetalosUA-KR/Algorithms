#include <iostream>

using namespace std;

int main()
{
    int tab[10] = {3,9,4,1,5,8,2,3,6,13};
    int b = tab[0];
    int n = 0;

    for(int i = 1; i < 10; i++)
    {
        int prom = 0;
        prom = n + tab[i];
        if(b >= n) n = b;
        else n = n;
        b = prom;
        cout<<b<<" "<<n<<endl;
    }
    //cout<<"b = "<<b<<endl;
    //cout<<"n = "<<n<<endl;

    return 0;
}
