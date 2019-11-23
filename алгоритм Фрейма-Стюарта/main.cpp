#include <iostream>
using namespace std;

int power(int a, int b)
{
    //cout<<"power"<<endl;
    int p = 1;
    for(int i = 0; i < b; i++)
    {
        p *= a;
    }
    return p;
}

int min(int abc[], int n)
{
    //cout<<"min"<<endl;
    int min = abc[0];
    for(int i = 1; i < n; i++)
    {
        if(abc[i] < min)
        {
            min = abc[i];
        }
    }
    //cout<<"potential moves -> "<<min<<endl;
    return min;
}

int hanoi (int rods, int disks)
{
    ///cout<<"disk: "<<disks<<"  ->  roads: "<<rods<<endl;
    int moves = 2147483647;
    if(disks == 0) return 0;
    if(disks == 1) return 1;
    if(rods == 3) return power(2,disks)-1;
    if(rods >= 3 && disks > 0)
    {
        //cout<<"hanoi"<<endl;
        int potential_moves[disks-1];
        for(int i = 0; i < disks; i++)
        {
            potential_moves[i-1] = 2 * hanoi(rods, i) + hanoi(rods - 1, disks - 1);

        }
        return min(potential_moves, disks - 1);
    }
    return moves;
}

int main()
{
    int rods, disks;
    cout<<"***** Tower of Hanoi (for n rods) *****"<<endl;
    cout<<"Enter no. of disks : ";
    cin>>disks;
    cout<<"Enter no. of rods : ";
    cin>>rods;
    if(disks > 1 && rods < 3)
    {
        cout<<"Invalid input rods must be greater than 2 for 2 or more disks"<<endl;
        return -1;
    }
    int moves = hanoi(rods, disks);
    cout<<"Minimum np. of moves are : "<<moves<<endl;

    return 0;
}




















