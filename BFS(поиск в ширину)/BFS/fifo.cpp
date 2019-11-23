#include <iostream>
#include "fifo.h"
#include "punkt.h"

using namespace std;

Fifo::~Fifo()
{
    while(size != 0)
    {
        pop();
    }
}

/**
 Add new element to queue, first we need to chek if this punkt is added, we dont add. Delete it
*/
void Fifo::push(Punkt val)
{
    Node * tmp = head;
    Node * newElement = new Node(val);
    while(tmp != nullptr)
    {
        if((tmp->value).getX() == newElement->value.getX() &&
           (tmp->value).getY() == newElement->value.getY())
        {
            delete newElement;
            return;
        }
        tmp = tmp->next;
    }
    if(head == nullptr)
    {
        head = newElement;
        currentValue = head;
    }
    else
    {
        Node * tmp = head;
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newElement;
    }
    size++;
}

/**
Get the first element of queue, and delete it
*/
Punkt Fifo::pop()
{
    //this is temporary :)
    if(head == nullptr)
    {
        Punkt p;
        p.setPunkt(-1,-1);
        cout<<"brak elementow"<<endl;
        return p;
    }
    Punkt v = head->value;
    Node * tmp = head;
    head = head->next;
    size--;
    delete tmp;
    return v;
}

/**
Get current element in list without delete it
*/
Punkt Fifo::getCurrentPunkt()
{
    if(currentValue == nullptr)
    {
        Punkt p;
        p.setPunkt(-1,-1);
        cout<<"brak elementow"<<endl;
        return p;
    }
    Punkt v = currentValue->value;
    Node * tmp = currentValue;
    currentValue = currentValue->next;
    return v;
}

/**
Get first element without delete
*/
Punkt Fifo::getHead()
{
    return head->value;
}



void Fifo::printFifo()
{
    Node * tmp = head;
    while(tmp != nullptr)
    {
        cout<<"x = "<<tmp->value.getX()<<"   y = "<<tmp->value.getY()<<endl;
        tmp = tmp->next;
    }
}



int Fifo::getSize()
{
    return size;
}





