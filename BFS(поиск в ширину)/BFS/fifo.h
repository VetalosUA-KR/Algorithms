#ifndef FIFO_H
#define FIFO_H
#include "punkt.h"

class Fifo
{
private:

    class Node
    {
    public:
        Punkt value;
        Node * next;
        Node (Punkt v, Node * n = nullptr)
        {
            value = v;
            next = n;
        }
    };
    Node * head = nullptr;
    Node * currentValue = nullptr;
    int size = 0;

public:
    Fifo() = default;
    virtual ~Fifo();
    void push(Punkt val);

    Punkt pop();
    Punkt getCurrentPunkt();
    Punkt getHead();

    void printFifo();
    int getSize();
    //Fifo& operator = (const Fifo& F);
};




#endif // FIFO_H
