#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

void paintBucket(int t[][10],int size, int x, int y, int new_color)
{

    int old_color = t[x][y];
    t[x][y] = new_color;
    if(y+1 < 10 && t[x][y+1] == old_color)paintBucket(t, 10, x, y+1, new_color);
    if(y-1 >= 0 && t[x][y-1] == old_color)paintBucket(t, 10, x, y-1, new_color);
    if(x+1 < 10 && t[x+1][y] == old_color)paintBucket(t, 10, x+1, y, new_color);
    if(x-1 >= 0 && t[x-1][y] == old_color)paintBucket(t, 10, x-1, y, new_color);
}

int main ()
{
    srand(time(NULL));
    int tab[10][10];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            tab[i][j] = rand()%2 + 0;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
    paintBucket(tab,10, 5,5,2);
    cout<<"**************"<<endl;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

