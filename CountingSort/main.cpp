#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

//int arr[15] = {4,1,3,0,2,7,1,5,4,9,3,9,6,2,4};
int arr[15];
int rez[15];
void createA(int tab[], int size)
{
    for(int i = 0; i < size; i ++)
    {
        tab[i] = rand() % 1000;
    }
}

void printArr(int tab[], int size)
{
    for(int i =0; i < size; i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

int f(int licz, int cyf)
{
    return (licz/int(pow(10,cyf)))%10;
}

void countSort(int tab[], int size, int cyf)
{

    int licz[10];
    for(int i = 0; i < 10; i++)
    {

        licz[i] = 0;
    }
    //printArr(licz, 10);

    for(int j = 0; j < size; j++)
    {
        licz[f(tab[j], cyf)]++;
    }
    //printArr(licz, 10);
    for(int i = 1; i < 10; i++)
    {
        licz[i] = licz[i-1]+licz[i];
    }

    for(int j = size-1; j >= 0; j--)
    {
        licz[f(tab[j], cyf)]--;
        rez[licz[f(tab[j], cyf)]] = tab[j];
    }

    for(int i = 0; i < size; i++)
    {
       tab[i] = rez[i];
    }
    cout<<"rez = ";printArr(tab, 15);
    //printArr(licz, 10);
}

int main()
{
    srand(time(0));
    createA(arr,15);
    printArr(arr, 15);
    countSort(arr, 15, 0);

    countSort(arr, 15, 1);

    countSort(arr, 15, 2);

    return 0;
}
