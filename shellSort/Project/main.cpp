#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

void createArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%(10*size)+0;
    }
}
void print(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<""<<arr[i]<<" ";
    }
}
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
int hibbard(int k){   return pow(2,k)-1;}
int papieron(int k){  return pow(2,k)+1;}
int sedgewick1(int k){return pow(4, k)+ 3 * pow(2, k-1) + 1;}
int tokuda(int k){return ceil(1.8*powf(2.25, k-1) - 0.8);}
int knuth(int k){return (pow(3,k)-1)/2;}

int mySequence1(int k){return pow(8, k)+6*pow(2,k)+1;}
int mySequence2(int k){return (2*k) + (pow(5,k+1)/k-1);}
int mySequence3(int k)
{return((pow(exp(1),(k+k)-1 )/pow(exp(1), k))*(exp(k)))/k+k+5;}


int* createArraySequence(int sizeOrigin, int &sizeSequence, int(*sequence)(int k))
{
    int step = 1;
    int k = 1;
    while(k < sizeOrigin)
    {
        k = sequence(step);
        step++;
    }
    step--;
    int *arr = new int[step];
    arr[0] = 1;
    for(int i = 1; i < step ; i++)
    {
        arr[i] = sequence(i);

    }
    sizeSequence = step;
    spreadArray(arr, sizeSequence);
    if(arr[sizeSequence-1] == arr[sizeSequence-2])
    {
        sizeSequence--;
    }
    print(arr, sizeSequence);
    cout<<endl;
    return arr;
}

void shellsort(int a[], int r, int(*seq)(int k))
{
    int sizeArraySequence = 0;
    int *arr = createArraySequence(r, sizeArraySequence, seq);

    int i, j, k, h, l;
    int v;
    for ( k = 0; k < sizeArraySequence; k++)
    {
       h = arr[k];
        for ( i = h; i < r; i++)
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
    delete [] arr;
}

int main()
{
    srand(time(0));

    int s = 2000000;
    int *arr1 = new int [s];
    int *arr2 = new int [s];
    int *arr3 = new int [s];
    int *arr4 = new int [s];
    int *arr5 = new int [s];
    int *arr6 = new int [s];
    for(int i = 0; i < s; i++)
    {
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = arr5[i] = arr6[i] = rand() % (10*s)+0;
    }
    int c1 = clock();
    shellsort(arr1,s, sedgewick1);
    int c2 = clock();
    shellsort(arr2, s, tokuda);
    int c3 = clock();
    shellsort(arr3, s, knuth);
    int c4 = clock();
    shellsort(arr4, s, mySequence1);
    int c5 = clock();
    shellsort(arr5, s, mySequence2);
    int c6 = clock();
    shellsort(arr6, s, mySequence3);
    int c7 = clock();
    cout<<endl<<endl;
    cout<<"sedgewick1 = "<<c2-c1<<endl;
    cout<<"tokuda = "<<c3-c2<<endl;
    cout<<"knuth = "<<c4-c3<<endl;
    cout<<"mySequence1 = "<<c5-c4<<endl;
    cout<<"mySequence2 = "<<c6-c5<<endl;
    cout<<"mySequence3 = "<<c7-c6<<endl;
    return 0;
}
