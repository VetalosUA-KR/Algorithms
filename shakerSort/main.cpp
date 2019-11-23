#include <iostream>

using namespace std;


void shekerSort(int arr[], int roz);
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main ()
{

    int roz = 20;
    int * arr = new int [roz];


    for(int i = 0; i < roz; i++)
    {
        arr[i] = rand()%50 + 1;
    }

    shekerSort(arr, roz);
    for(int i = 0; i < roz; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}


void shekerSort(int arr[], int roz)
{
    for(int i = 0; i < roz-i; i++)
    {
        for(int l = 0; l < roz; l++)
        {
            if(arr[l] >= arr[l+1])
            {
                swap(arr[l], arr[l+1]);
            }
        }
        for(int r = roz-i; r > 0; r--)
        {
            if(arr[r] <= arr[r-1])
            {
                swap(arr[r], arr[r-1]);
            }
        }
    }
}
