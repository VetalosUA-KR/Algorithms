#include "LongNumber.h"
#include <iostream>
#include <cstring>

using namespace std;



LongNumber::LongNumber(char* number, int d)
{
    int i = 0;
    if(number[0] != '-')
    {
        head = new Node('+');
    }
    else
    {
        head = new Node('-');
        i++;
    }
    //tail = head;
    head->setDigit(d);

    for(; i < strlen(number); i++)
    {
        addElement(number[i]);
    }
}

void LongNumber::addElement(char n)
{
    Node * newElement = new Node(n);
    Node * tmp = head;
    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = newElement;
    //tail = newElement;
    size++;
}

LongNumber & LongNumber::operator = (const LongNumber & ln)
{
    if(this == &ln) return * this;

}

LongNumber::~LongNumber()
{
    while(head != nullptr)
    {
        Node * toDel = head;
        head = head->next;
        delete toDel;
        size--;
    }
    //tail = nullptr;
}

bool helpOperator(LongNumber left, LongNumber right)
{
    /// if RIGHT < LEFT and equal signs
    if(left.getSize() < right.getSize() && left.getHead()->data == right.getHead()->data)
    {
        /// if numbers is negative
        if(left.getHead()->data == '-')
        {
            if(left.getSize() < right.getSize()) return false;
            else return true;
        }
        /// if numbers is positive
        else
        {
            if(left.getSize() < right.getSize()) return true;
            else return false;
        }
    }
    /// if RIGHT > LEFT and equal signs
    else if (left.getSize() > right.getSize() && left.getHead()->data == right.getHead()->data)
    {
        /// if numbers is negative
        if(left.getHead()->data == '-')
        {
            if(left.getSize() < right.getSize()) return false;
            else return true;
        }
        /// if numbers is positive
        else
        {
            if(left.getSize() < right.getSize()) return true;
            else return false;
        }
    }
    /// if length LEFT = length RIGHT
    else
    {
        /// signs number is different
        if(left.getHead()->data != right.getHead()->data)
        {
            if(left.getHead()->data == '+') return false;
            else return true;
        }
        /// signs number is equal
        else
        {
            if(left.getHead()->data == '-')
            {
                LongNumber::Node * tmpLeft = left.getHead();
                LongNumber::Node * tmpRight = right.getHead();
                while(tmpLeft->next != nullptr)
                {
                    if(int(tmpLeft->data) < int(tmpRight->data))
                    {
                        return false;
                    }
                    tmpLeft = tmpLeft->next;
                    tmpRight = tmpRight->next;
                }
                return true;
            }
            else
            {
                LongNumber::Node * tmpLeft = left.getHead();
                LongNumber::Node * tmpRight = right.getHead();
                while(tmpLeft->next != nullptr)
                {
                    if(int(tmpLeft->data) < int(tmpRight->data))
                    {
                        return true;
                    }
                    tmpLeft = tmpLeft->next;
                    tmpRight = tmpRight->next;
                }
                return false;
            }
        }
    }
}
bool LongNumber::operator < (const LongNumber ln) const
{
    return (helpOperator(*this, ln));
}
bool LongNumber::operator > (const LongNumber ln) const
{
    return !(helpOperator(*this, ln));
}


ostream & operator <<(ostream & os, LongNumber & ln)
{
    ln.printNumber();
    return os;
}

istream & operator >>(istream & is, const LongNumber & ln)
{

}



void LongNumber::printNumber()
{
    Node * tmp = head;
    while(tmp)
    {
        if(tmp->data != '+')
            cout<<tmp->data;
        tmp = tmp->next;
    }
    /*cout<<endl;

    cout<<"head = "<<head->data;
    cout<<"\t digit = "<<head->getDigit();
    cout<<"\t dlugosc = "<<size;
    cout<<"\t tail = "<<tail->data<<endl;*/
}











