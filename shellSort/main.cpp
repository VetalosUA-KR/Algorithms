#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

//HELLOOOOOO
void createArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%size*2+1;
    }
}

void print(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<""<<arr[i]<<" ";
    }
}

int countSize(int s)
{
    int rez = 1;
    int k = 1;
    while(rez < s)
    {
        rez = pow(2,k) + 1;
        k++;
    }
    return k-1;
}


void createSequence(int arr[], int size)
{
    int rez = 1;
    int k = 1;
    while(rez < size)
    {
        arr[k-1] = rez;
        rez = pow(2,k) + 1;
        k++;
    }
}
/********************************************////     4^r+3*2^(k-1)+1
void createSequence2(int arr[], int size)
{
    int rez = 1;
    int k = 1;
    while(rez < size)
    {
        arr[k-1] = rez;
         rez = pow(4, k) + 3 * pow(2,k-1) + 1;
        k++;
    }
}
int countSize2(int s)
{
    int rez = 1;
    int k = 1;
    while(rez < s)
    {
        //cout<<rez<<" ";
        rez = pow(4, k) + 3 * pow(2,k-1) + 1;
        k++;
    }
    return k-1;
}
////////////////////////////////////////////////////////////////////

/********************************************////     1,8 * 2,25^(k-1) - 0,8
void createSequence3(int arr[], int size)
{
    int rez = 1;
    int k = 1;
    while(rez < size)
    {
        rez = ceil(1.8 * pow(2.25, k-1) - 0.8);

        arr[k-1] = rez;
        k++;
    }
}
int countSize3(int s)
{
    int rez = 1;
    int k = 1;
    while(rez < s)
    {
        cout<<rez<<" ";
        rez = 1.8 * pow(2.25, k-1) - 0.8;
        k++;
    }
    cout<<endl;
    return k-1;
}
////////////////////////////////////////////////////////////////////

void spreadArray(int arr[], int size)
{
    int tmp;
    for(int i = 0; i < size/2; i++)
    {
        tmp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = tmp;
    }
}


void shellsort3(int a[], int r)
{
    int sizeSequence = countSize3(r);/// rachujemy dlugosc ciagu
    int arrSequence[sizeSequence];  /// tworzymy tablice potrzebnej dlugosci
    createSequence3(arrSequence, r); /// przypisujemy wartosci do tej tabeli

    cout<<"arr sequence        =   ";
    print(arrSequence, sizeSequence);
    cout<<endl;

    spreadArray(arrSequence, sizeSequence);

    cout<<"spread arr sequence =   ";
    print(arrSequence, sizeSequence);
    cout<<endl;


    int i, j, k, h, l;
    int v;
    for ( k = 0; k < sizeSequence; k++)
    {
       h = arrSequence[k];
        for ( i = h; i < r; i++) /// zamiast i <= r  trzeba i < r
        {
            v = a[i];
            j = i;
            while (j >= h && a[j-h] > v)
            {
                a[j] = a[j-h];
                j -= h;
            }
            a[j] = v;
        }

    }
}

//Собственная реализация
/*void shellsort(int arr[], int size, int arrK[], int sizeAK)
{
    for(int i = 0; i < sizeAK; i++)
    {
        int step = 0;
        for(int q = 0; q < arrK[i]; q++)
        {
            int s = 0;
            //int sorArr[int(ceil((1.0*size)/arrK[i])-1)];
            int sizeHelpArray = 0;
            for(int j = 0; j < ceil((1.0*size)/arrK[i]) && s+step < size; j++)
            {
                    s += arrK[i];
                    sizeHelpArray++;
            }
            s = 0;
            //cout<<" (size help array = "<<sizeHelpArray<<")"<<endl;
            int helpArray[sizeHelpArray];
            for(int j = 0; j < ceil((1.0*size)/arrK[i]) && j < sizeHelpArray; j++)
            {
                helpArray[j] = arr[s+step];
                s += arrK[i];
            }

            /// w tym miejscu bedzie sortowanie pomocniczej tabeli

            /// przypisanie z pomocniczej tabeli w odpowiednie miejsca
            //cout<<"array = (";
            //print(helpArray, sizeHelpArray);
            //cout<<") "<<endl;
            step++;
        }
        //cout<<"-----------------------------"<<endl;
    }
}
*/


int main()
{
    srand(time(0));

    int size = 400;

    //int arr[size]={1,1,98,3,21,15,64,3,9,98};
    int arr[size];
    createArray(arr, size);
    ///print(arr, size);
    cout<<endl<<endl;
    shellsort3(arr, size);
    cout<<endl;
    ///print(arr, size);
    cout<<endl;


    ///Проверка скорости выполнения
    /*int s = 100000;
    int *arr1 = new int [s];
    int *arr2 = new int [s];
    for(int i = 0; i < s; i++)
    {
        arr1[i] = arr2[i] = rand() % 1000;
    }
    int sas = 12;
    int arrStep[sas] = {33936, 13776, 4592, 1968, 861, 336, 112, 48, 21, 7, 5, 1 };
    int c1 = clock();
    shellsort(arr1,s);
    int c2 = clock();
    shellsort(arr2, s, arrStep, sas);
    int c3 = clock();
    cout<<"shellsort = "<<c2-c1<<endl;
    cout<<"my shellsort = "<<c3-c2<<endl;*/


    return 0;
}










