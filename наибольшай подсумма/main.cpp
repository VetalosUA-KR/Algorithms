#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

void createarr(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand() % (size*3) - (size*2);
    }
}
void printArr(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    cout<<endl;
}

int main()
{
    srand(time(0));

    int size = 9;
    //int arr[size] = {10 , 3 , -3 , 1, 3 , 4,  -3 , -16 , -8};
    int arr[size];
    createarr(arr,size);
    printArr(arr,size);

    int _start = 0;
    int _stop = 0;

    int s=0,mins=0,ans=0;

    for (int i=0; i<size; i++)
    {
        s+=arr[i];
        if(mins != min(mins,s))
        {
            _start = i+1;
            cout<<"START = "<<i<<endl;
        }
        mins=min(mins,s);
        if(ans != max(ans,s-mins))/// минус на минус даст плюс
        {
             _stop = i;
            cout<<"STOP = "<<i<<" ";
            cout<<"ans = "<<max(ans,s-mins)<<endl;
        }
        ans=max(ans,s-mins);
    }

    cout<<endl;

    /*if(_start >= _stop)
    {
        int sum = 0;
        int sumPreviouse = 0;
        int start = 0;
        int stop = 0;

        for(int i = 0; i < size; i++)
        {
            sum += arr[i];
            if(sumPreviouse > sum)
            {
                start = i+1;
            }
            if(sum > sumPreviouse)
            {
                stop = i;
            }
            sumPreviouse = sum;
        }
        cout<<"start = "<<start<<"   stop = "<<stop<<endl;
    }
    else
    {*/
        cout<<"max summa podciag = "<<ans<<endl;
        cout<<"poczatek = "<<_start<<endl;
        cout<<"koniec = "<<_stop<<endl;
        for(int i = _start; i <= _stop; i++)
        {
            cout<<arr[i]<<" ";
        }
    //}

    cout<<endl;

    return 0;
}





























