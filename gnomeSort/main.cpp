#include <iostream>

using namespace std;


void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void gnomeSort(int arr[], int roz)
{
    for(int i = 0; i+1 < roz; ++i)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i], arr[i+1]);
            if(i != 0) i -= 2;
        }
    }
}

int main ()
{

    int roz = 10;

    int * arr = new int [roz];

    for(int i = 0; i < roz; i++)
    {
        arr[i] = rand()%roz*2 + 1;
    }


    gnomeSort(arr, roz);


    for(int i = 0; i < roz; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
