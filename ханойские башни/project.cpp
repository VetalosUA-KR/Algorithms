#include <iostream>
#include <fstream>

using namespace std;

void swap(int &a, int &b)
{
    int buf = a;
    a = b;
    b = buf;
}

/**
    Алгоритм перелаживает по два диска, перелаживание двух дисков занимает 3 хода, поэтому cout'ов 3
*/
void hanArray(int n, int arr[], int size)
{
    if(n == 0)
    {
        return;
    }
    if(n == 1)
    {
        cout<<arr[0]<<" "<<arr[1]<<endl;
    }
    else
    {
        /**
            Переставляем "башни" в массиве таким образом:
            - первую башню не трогаем
            - башня которая была второй занимает крайнюю правую позицию
            - остальные башни сдвигаются на 1 в лево
            - вызываем рекурсивнюю функцию для нового порядка башень
        */
        int newArr[size];
        newArr[0] = arr[0];
        for(int i = 1; i < size; i++) {newArr[i] = arr[i+1];}
        newArr[size-1] = arr[1];
        hanArray(n - 2, newArr, size);

        cout<<arr[0]<<" "<<arr[3]<<endl;
        cout<<arr[0]<<" "<<arr[1]<<endl;
        cout<<arr[3]<<" "<<arr[1]<<endl;

        /**
            Переставляем "башни" в массиве таким образом:
            - 1 башню меняем местами с 3
            - положение остальных башень остается прежнее
            - вызываем рекурсивнюю функцию для нового порядка башень
        */
        for(int i = 0; i < size; i++) {newArr[i] = arr[i];}
        swap(newArr[0], newArr[2]);
        hanArray(n - 2, newArr, size);
    }
}


int main()
{
    int towers = 5; /// Кол-во башень
    int disks = 13;  /// Кол-во дисков

    int arr[towers];
    /// Делаем так что бы наш массив башень принял вид (1, x, 2, 3,...x-1)
    /// где x - количество башень
    arr[0] = 1;
    for(int i = 2; i < towers; i++)
    {
        arr[i] = i;
    }
    arr[1] = towers;

    hanArray(disks, arr, towers);

    return 0;
}


