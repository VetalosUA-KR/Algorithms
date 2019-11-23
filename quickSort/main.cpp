#include <iostream>

using namespace std;


void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void quickSort(int arr[], int b0, int e0, int size)
{
    int d = arr[e0];
    int b = b0;
    int e = e0;

    do
    {
        while(arr[b] < d)
            ++b;
        while(arr[e] > d)
            --e;
        if(b <= e)
        {
            swap(arr[b], arr[e]);
            ++b;
            --e;
        }
    }while (b <= e);

    if(e > b0)
    {
        quickSort(arr, b0, e, e-b0);
    }
    if(b < e0)
    {
        quickSort(arr, b, e0, e0-b);
    }
}

int main()
{

    int size = 20;

    int * arr = new int[size];

    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%200+1;
    }

    quickSort(arr, 0, size-1, size);

    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
