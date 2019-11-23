#ifndef PUNKT_H
#define PUNKT_H
#include <iostream>

using namespace std;

class Punkt
{
    int x;
    int y;
    int step = 0;
public:
    void setPunkt(int _x, int _y);
    int getX();
    int getY();
    int getStep();
    friend ostream& operator<<(ostream& os, const Punkt& Pkt);
};




#endif // PUNKT_H
