#include <iostream>
#include <stdlib.h>

using namespace std;

int main ()
{

    /*for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
           if(((i/3)+(j/3))%2)cout<<" ";
           else cout<<"*";
        }
        cout<<endl;
    }*/


    /*int tab [30];
    tab[0] = 1;

    for(int i = 1; i < 30; i++)
    {
        tab[i] = tab[i-1]+rand()%5;
    }*/

    int roz = 13;

    //cin>>roz;

    int tab [roz] = {1,10,23,48,7,60,92,1,3,34,28,32,100};

    /*int l;
    for(int i = 0; i < roz; i++)
    {
        cin>>l;
        tab[i] = l;
    }*/

    for(int i = 0; i < roz; i++)
    {
        cout<<tab[i]<<" ";
    }

    cout<<endl<<"************"<<endl;

    int rez = 0;
    for(int i = 0; i < roz; )
    {
        if((tab[i] + tab[i+2]) >= (tab[i+1]+tab[i+3]))
        {
            rez += tab[i] + tab[i+2];
            cout<<tab[i]<<" "<<tab[i+2]<<" ";
            i += 4;
        }
        else
        {
            rez += tab[i+1]+tab[i+3];
            cout<<tab[i+1]<<" "<<tab[i+3]<<" ";
            i += 5;
        }
    }
    cout<<endl<<"************"<<endl;
    cout<<rez;


    return 0;

}

/*bool czyJest(int * t, int c, int roz)
{
    for(int i = 0; i < roz; i ++)
    {
        if(t[i] == c)
        {
            return 1;
        }
    }
    return 0;
}*/



bool binarySearch(int * tab, int licz, int size)
{
    int levo = 0;
    int pravo = size-1;

    while(pravo >= levo)
    {
        int center = (levo+pravo)/2;
        if(tab[center] == licz)
        {
            return 1;
        }
        else
        {
            if(tab[center] > licz)
            {
                pravo = center-1;
            }
            else
            {
                levo = center+1;
            }
        }
    }
    return 0;
}


bool binarySearch(int * tab, int levo, int pravo, int liczba)
{

    if(pravo < levo)
    {
        return false;
    }

    if(tab[(levo+pravo)/2] == liczba)
    {
        return 1;
    }
    else
    {
        if(tab[(levo+pravo)/2] > liczba)
        {
            binarySearch(tab, levo, ((levo+pravo)/2)-1, liczba);
        }
        else
        {
            binarySearch(tab,((levo+pravo)/2)+1, pravo, liczba);
        }
    }
}















