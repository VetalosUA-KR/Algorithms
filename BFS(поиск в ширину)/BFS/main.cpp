#include <iostream>
#include "fifo.h"
#include "punkt.h"

#define SIZE 3


using namespace std;

/// Создание двумерного массива
void createArray(int arr[][SIZE], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }
}

/// Вывод на экран
void printArr(int arr[][SIZE], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<arr[i][j];
            if(j < size-1)
                cout<<" ";
        }
        cout<<endl;
    }
}

///Следующее поколение
void findWay(int arr[][SIZE], int size)
{
    /*Punkt punkt;
    Fifo queu;

    punkt.setPunkt(0,0);
    queu.push(punkt);

    for(int x = 0; x < size; x++)
    {
        for(int y = 0; y < size; y++)
        {
            if(y+1 < size)
            {
                punkt.setPunkt(x,y+1);
                queu.push(punkt);
            }
            if(y-1 >= 0)
            {
                punkt.setPunkt(x,y-1);
                queu.push(punkt);
            }
            if(x+1 < size)
            {
                punkt.setPunkt(x+1,y);
                queu.push(punkt);
            }
            if(x-1 >= 0)
            {
                punkt.setPunkt(x-1,y);
                queu.push(punkt);
            }
        }
    }
    queu.printFifo();
    cout<<endl;*/

    Fifo generealQueue;
    Punkt punkt;
    punkt.setPunkt(0,0);
    generealQueue.push(punkt);


    /// cp - current punkt
    Punkt cp = generealQueue.getHead();///Get start point without delet it

    while(cp.getY() != 2 || cp.getX() != 2)
    {

        if(cp.getX()+1 < size)
        {
            punkt.setPunkt(cp.getX()+1, cp.getY());
            generealQueue.push(punkt);
        }
        if(cp.getX()-1 >= 0)
        {
            punkt.setPunkt(cp.getX()-1, cp.getY());
            generealQueue.push(punkt);
        }
        if(cp.getY()-1 >= 0)
        {
            punkt.setPunkt(cp.getX(), cp.getY()-1);
            generealQueue.push(punkt);
        }
        if(cp.getY()+1 < size)
        {
            punkt.setPunkt(cp.getX(), cp.getY()+1);
            generealQueue.push(punkt);
        }
        cp = generealQueue.getCurrentPunkt();///Get next current point without delet it

        cout<<"current x = "<<cp.getX()<<"  --  "<<"current y = "<<cp.getY()<<" --->>> ";
        cout<<(cp.getY() != 2 || cp.getX() != 2)<<endl;
    }
    generealQueue.printFifo();

}

int main()
{



    int arr[SIZE][SIZE];

    createArray(arr, SIZE);

    printArr(arr, SIZE);
    cout<<"******************"<<endl;
    findWay(arr, SIZE);





    return 0;
}










