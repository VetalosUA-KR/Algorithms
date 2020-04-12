#include "BTree.cpp"
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


int main()
{
    srand(time(NULL));

    BTree b1;
    for(int i = 0; i < 20; i++)
    {
        int r = rand()%200;
        cout<<"add -> "<<r<<endl;
        b1.insert(r);
    }

    b1.print();
    return 0;
}
