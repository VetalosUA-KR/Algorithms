#include <iostream>
#include <time.h>

using namespace std;

void find (int t[][10], int x, int y, int krok)
{
    //if(t[x][y] != 1) return;
    if(t[x][y] == -1)return;
    if(t[x][y] == 0)return;

    if(t[x][y] > krok)
    {
        t[x][y] = krok ;
    }
    else
    {
        t[x][y] = krok;
    }
    krok++;
    /*if(t[x][y+1] == 1)*/find(t, x, y+1, t[x][y]);
    /*if(t[x][y-1] == 1)*/find(t, x, y-1, t[x][y]);
    /*if(t[x+1][y] == 1)*/find(t, x+1, y, t[x][y]);
    /*if(t[x-1][y] == 1)*/find(t, x-1, y, t[x][y]);

}


int main()
{

    srand(time(NULL));
    int arr[10][10];



    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i == 0 || i == 9)
            {
                arr[i][j] = 0;
            }
            else if(j == 0 || j == 9)
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = 1;
            }
            //arr[i][j] = 1;
        }
    }
    for(int i = 0; i < 20; i++)
    {
        arr[rand()%8+1][rand()%8+1] = 0;
    }
    arr[1][1] = 1;
    arr[8][8] = -1;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"*******************"<<endl;

    int n = 1;
    find(arr, 1, 1, n);

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    for(int i = 1; i < 9; i++)
    {
        for(int j = 1; j < 9; j++)
        {

        }
    }

    return 0;
}
