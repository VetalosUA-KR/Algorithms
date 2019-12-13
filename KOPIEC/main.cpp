#include <iostream>

using namespace std;
int tab[100] = {0,17,14,15,4,13,12,15,4,2,7,9};
int roz = 11;


void change(int & a, int &b)
{
    int buf = a;
    a = b;
    b = buf;
}

void fixFromBelow()
{
    int tmp = roz;
    while(tmp/2 > 0 && tab[tmp] > tab[tmp/2])
    {
        change(tab[tmp], tab[tmp/2]);
        tmp /= 2;
    }

}

void add(int n)
{
    roz++;
    tab[roz] = n;
    fixFromBelow();
}

void zdejmi()
{
    roz--;
    swap(tab[1], tab[roz]);
    cout<<"zdejmovana = "<<tab[1]<<endl;
    int tmp = 1;

    while(tmp*2 <= roz)
    {
        if(tmp * 2+1 > roz && tab[tmp * 2] > tab[tmp])
        {
            swap(tab[tmp], tab[tmp * 2]);
            tmp = tmp * 2;
        }
        else
        {
            int poz;
            int max;
            if(tab[tmp*2] > tab[tmp*2+1])
            {
                max = tab[tmp*2];
                poz = tmp*2;
            }
            else if(tab[tmp*2] < tab[tmp*2+1])
            {
                max = tab[tmp*2+1];
                poz = tmp*2+1;
            }
            else break;
            if(tab[tmp] < max)
            {
                swap(tab[tmp], tab[poz]);
                tmp = poz;
            }
        }
    }
}

void print()
{
    for(int i = 1; i <= roz; i++)
    {
        cout<<tab[i]<<" ";
    }
}

int main()
{

    /*for(int )
    {

    }*/
    print();
    cout<<endl;

    zdejmi();
    zdejmi();
    zdejmi();
    zdejmi();
    cout<<endl;
    print();


    return 0;
}
