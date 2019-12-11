#include <iostream>

using namespace std;

int main()
{

    int arr1[3] = {3,4,2};/// r1
    int arr2[3] = {2,4,3};/// r2
    int arr3[3] = {1,3,2};/// cheng

    int sum = 0;

    for(int i = 0; i < 3; i++)
    {
        if(arr1[i] < arr2[i]+arr3[i])
        {
            sum += arr1[i];
        }
        else
        {
            sum += arr2[i]+arr3[i];
        }
    }


    return 0;
}
