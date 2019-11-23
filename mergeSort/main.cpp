#include <iostream>

using namespace std;

void merge (int *a, int s, int e)
{
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;

    int temp[100];

    while(i<=mid && j<=e)
    {
        if(a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    while(i<=mid)
    {
        temp[k++] = a[i++];
    }
    while(j<=e)
    {
        temp[k++] = a[j++];
    }

    ///Копируем все элементы в оригинальный массив
    for(int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
}

void mergeSort(int a[], int s, int e)
{
    if(s>=e)
    {
        return;
    }

    int mid = (s+e)/2;

    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);

    /// Склеиваем две части
    merge(a,s,e);

}

int main ()
{
    int size = 5;
    int * arr = new int [size];

    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%30+1;
    }

    mergeSort(arr, 0, size-1);

    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}





