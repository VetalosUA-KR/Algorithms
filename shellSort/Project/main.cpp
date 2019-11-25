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
int hibbard(int k){   return pow(2,k)-1;}                     /// 262143  131071  65535  32767  16383  8191  4095  2047  1023  511  255  127  63  31  15  7  3     1
int papieron(int k){  return pow(2,k)+1;}                     /// 262145  131073  65537  32769  16385  8193  4097  2049  1025  513  257  129  65  33  17  9  5  3  1
int sedgewick1(int k){return pow(4, k)+ 3 * pow(2, k-1) + 1;} /// 262913          65921         16577        4193        1073       281       77      23     8     1
int tokuda(int k){return ceil(1.8*powf(2.25, k-1) - 0.8);}    ///         153401  68178  30301  13467  5985        2660  1182  525  233  103      46  20     9  4  1
int knuth(int k){return (pow(3,k)-1)/2;}                      /// 265720          88573  29524         9841  3280        1093  364       121      40  13     4     1

int mySequence1(int k){return pow(8, k)+6*pow(2,k)+1;}        /// 262529                 32961               4193              561            89      21           1
int mySequence2(int k){return (2*k) + (pow(5,k+1)/k-1);}      /// 244155          55816         13031        3133        788        213       65      25           1
int mySequence3(int k)                                        ///                 63213                9990              1630       283       57      17     8     1
{return((pow(exp(1),(k+k)-1 )/pow(exp(1), k))*(exp(k)))/k+k+5;}

int sedgewick2(int k)
{
    int l = 9*(pow(4, k-1) - pow(2, k-1)) + ceil(powf(1.4, k+1));
    int q = 6 * pow(2, k) + 1;
    return l-q;
}

int* createArray(int sizeOrigin, int &sizeSequence, int(*sequence)(int k))
{
    int step = 1;
    int k = 1;

    while(k < sizeOrigin)
    {
        k = sequence(step);
        step++;
    }

    int *arr = new int[step];

    arr[0] = 1;
    for(int i = 1; i < step ; i++)
    {
        arr[i] = sequence(i);

    }
    step--;
    sizeSequence = step;// размер массива "делителей"
    spreadArray(arr, sizeSequence); // разворачиваем, делаем от большего к меньшему

    if(arr[sizeSequence-1] == arr[sizeSequence-2])
    {
        sizeSequence--;
    }

    print(arr,sizeSequence);
    cout<<endl;

    return arr;

}

void shellsort(int a[], int r, int(*seq)(int k))
{
    int sizeArraySequence = 0;
    int *arr = createArray(r, sizeArraySequence, seq);

    int i, j, k, h, l;
    int v;
    for ( k = 0; k < sizeArraySequence; k++)
    {
       h = arr[k];
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
    delete [] arr;
}

int main()
{
    srand(time(0));
    /*int size = 30;

    int arr[size];
    createArray(arr, size);
    print(arr, size);

    cout<<endl;
    shellsort(arr, size, papieron);
    print(arr, size);*/



    ///Проверка скорости выполнения
    int s = 2000000;
    int *arr1 = new int [s];
    int *arr2 = new int [s];
    for(int i = 0; i < s; i++)
    {
        arr1[i] = arr2[i] = rand() % (10*s)+0;
    }

    int c1 = clock();
    shellsort(arr1,s, sedgewick1);
    int c2 = clock();
    shellsort(arr2, s, mySequence3);
    int c3 = clock();
    cout<<"sedgewick1 = "<<c2-c1<<endl;
    cout<<"mySequence3 = "<<c3-c2<<endl;


    return 0;
}
