#include <iostream>
#include <time.h>

using namespace std;

void sortAlgorytm(int tab[], int roz);

void insertSort(int tab[], int roz);
void insertSort2(int tab[], int roz);

int main ()
{

    //int roz = 10;
    //int tablica[10] = {2,4,1,6,3,23,12,98,22,9};
    int roz = 50000;
    int *t1 = new int[roz];
    int *t2 = new int[roz];
    int *t3 = new int[roz];

    for(int i = 0; i < roz; i++)
    {
        t3[i]=t2[i]=t1[i] = rand();
    }
    int c1 = clock();
    insertSort(t1, roz);
    int c2 = clock();
    insertSort2(t2, roz);
   int c3 = clock();

    cout<<"sort = "<<c2-c1<<endl;
    cout<<"sort2 = "<<c3-c2<<endl;
    //insertSort2(tablica, roz);



    /*for(int i = 0; i < roz; i++)
    {
        cout<<tablica[i]<<" ";
    }*/
    return 0;
}

void insertSort(int tab[], int roz)
{
    int tmp = tab[0];

    for(int i = 1; i < roz; i++)
    {
        int index = i-1;
        tmp = tab[i];
        while(tab[index] > tmp && index >= 0)
        {
            tab[index+1] = tab[index];
            index--;
        }
        tab[index+1] = tmp;
    }
}

void insertSort2(int tab[], int roz)
{
    int indexElement = 0;
    for(int i = 1; i < roz; i++)
    {
        if(tab[i] < tab[indexElement])
        {
            indexElement = i;
        }
    }
    swap(tab[0], tab[indexElement]);

    int tmp = tab[0];

    for(int i = 1; i < roz; i++)
    {
        int index = i-1;
        tmp = tab[i];
        while(tab[index] > tmp)
        {
            tab[index+1] = tab[index];
            index--;
        }
        tab[index+1] = tmp;
    }
}

void sortAlgorytm(int tab[], int roz)
{
    int minElement = tab[0];
    int indexElement = 0;

    for(int j = 0; j < roz-1; j++)
    {
        indexElement = j;
        for(int i = j; i < roz; i++)
        {
            if(tab[i] < tab[indexElement])
            {
                indexElement = i;
            }
        }
        swap(tab[j], tab[indexElement]);
    }
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}







