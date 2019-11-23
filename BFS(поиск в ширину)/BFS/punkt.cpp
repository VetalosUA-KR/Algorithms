#include "punkt.h"

void Punkt::setPunkt(int _x, int _y)
{
    x = _x;
    y = _y;
}

int Punkt::getX()
{
    return x;
}

int Punkt::getY()
{
    return y;
}

ostream& operator<<(ostream& os, const Punkt& Pkt)
{
    os<<'['<<Pkt.x<<","<<Pkt.y<<']';
    return os;
}

int Punkt::getStep()
{
    return step;
}


