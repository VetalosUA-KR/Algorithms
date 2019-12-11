#include "LongNumber.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void LongNumber::addElement(int d)
{
    Node * newElement = new Node(d);
    if(head == nullptr)
    {
        head = newElement;
        tail = newElement;
    }
    else
    {
        Node * tmp = head;
        while(tmp->next)
        {
            tmp = tmp->next;
        }
        newElement->previous = tail;
        tmp->next = newElement;
        tail = newElement;
    }
    size++;
}

void LongNumber::addFront(int d)
{
    Node * newElement = new Node(d);
    if(head == nullptr)
    {
        head = newElement;
        tail = newElement;
    }
    else
    {
        if(head->previous != nullptr)
        {
            //cout<<"IN"<<"old number = "<<head->data<<"\t new number = "<<d<<endl;
            head->previous->data += d;
            head = head->previous;
        }
        else
        {
            head->previous = newElement;
            newElement->next = head;
            head = newElement;
        }
    }
}


void LongNumber::addFront2(int d)
{
    Node * newElement = new Node(d);
    head->previous = newElement;
    newElement->next = head;
    //head = newElement;
}


LongNumber::LongNumber(string number, int dig)
{
    int i = 0;
    digit = dig;
    if(number[0] == '-')
    {
        sign = -1;
        i++;
    }
    else
    {
        sign = +1;
    }
    for(; i < number.size(); i++)
    {
        addElement(number[i]-'0');
    }
}

LongNumber::LongNumber(const LongNumber& ln)
{
    deletAll();
    digit = ln.digit;
    sign = ln.sign;

    Node * tmp = ln.head;
    while(tmp)
    {
        addElement(tmp->data);
        tmp = tmp->next;
    }
}

LongNumber::~LongNumber()
{
    deletAll();
}

void LongNumber::deletAll()
{
    while(head)
    {
        Node * toDelete = head;
        head = head->next;
        size--;
    }
}


LongNumber& LongNumber::operator=(const LongNumber& ln)
{
    if(this == &ln) return *this;
    deletAll();
    digit = ln.digit;
    sign = ln.sign;

    Node * tmp = ln.head;
    while(tmp)
    {
        addElement(tmp->data);
        tmp = tmp->next;
    }
    return *this;
}

bool helpOperator(LongNumber & left, LongNumber & right)
{
    /// if length LEFT > length RIGHT and equal signs
    if(left.size > right.size && left.sign == right.sign)
    {
        return (left.sign == -1);
    }
    /// if length LEFT < length RIGHT and equal signs
    else if (left.size < right.size && left.sign == right.sign)
    {
        return (right.sign == 1);
    }
    /// if length LEFT = length RIGHT
    else
    {
        /// signs number is different
        if(left.sign != right.sign)
        {
            if(left.sign == 1) return false;
            else return true;
        }
        /// signs number is equal
        else
        {
            /// temporary
            if(left.size == 1)
            {
                return (left.head->data > right.head->data) ? (left.sign == -1) : (left.sign == 1);
            }
            LongNumber::Node * tmpLeft = left.head;
            LongNumber::Node * tmpRight = right.head;
            while(tmpLeft->next != nullptr)
            {
                if(tmpLeft->data > tmpRight->data)
                {
                    return (left.sign == 1) ? false : true;
                }
                tmpLeft = tmpLeft->next;
                tmpRight = tmpRight->next;
            }
            return (left.sign == 1) ? true : false;
        }
    }
}

bool LongNumber::operator < ( LongNumber& ln)
{
    if(*this == ln) return false;
    return helpOperator(*this, ln);
}
bool LongNumber::operator > ( LongNumber& ln)
{
    if(*this == ln) return false;
    return !(helpOperator(*this, ln));
}
bool LongNumber::operator==(LongNumber& ln)
{
    if(size == ln.size && sign == ln.sign)
    {
        Node * tmpLeft = head;
        Node * tmpRight = ln.head;
        while(tmpLeft)
        {
            if(tmpLeft->data != tmpRight->data)
            {
                return false;
            }
            tmpLeft = tmpLeft->next;
            tmpRight = tmpRight->next;
        }
        return true;
    }
    else return false;
}

/**
change, if some number is negative
*/
LongNumber LongNumber::operator + (LongNumber& ln)
{
    LongNumber newNumber;
    Node * tmpUp = tail;
    Node * tmpDown = ln.tail;

    while(tmpUp || tmpDown)
    {
        int upNumber = (tmpUp != nullptr) ? tmpUp->data : 0;
        int downNumber = (tmpDown != nullptr) ? tmpDown->data : 0;
        int mod = (upNumber + downNumber) / ln.digit;
        newNumber.addFront((upNumber + downNumber) % ln.digit);
        if(mod > 0)
        {
            newNumber.addFront2(mod);
        }
        if(tmpUp)tmpUp = tmpUp->previous;
        if(tmpDown)tmpDown = tmpDown->previous;
    }

    while(newNumber.head->previous != nullptr)
    {
        newNumber.head = newNumber.head->previous;
    }

    /// THIS !!!
    if(sign == -1 && ln.sign == -1) newNumber.sign = -1;
    newNumber.printNumber();
    return newNumber;
}

LongNumber LongNumber::operator-(LongNumber& ln2)
{
    LongNumber ln = ln2;
    LongNumber left = *this;

    LongNumber newNumber;
    Node * tmpUp;
    Node * tmpDown;
    if(*this > ln)
    {
        tmpUp = left.tail;
        tmpDown = ln.tail;
        //cout<<"levoe bolshe";
    }
    else if (*this < ln)
    {
        tmpUp = ln.tail;
        tmpDown = left.tail;
        newNumber.sign = -1;
        //cout<<"pravoe bolshe";
    }
    else
    {
        newNumber.addFront(0);
        ///newNumber.printNumber();
        return newNumber;
    }

    while(tmpUp && tmpDown)
    {
        if(tmpUp->data - tmpDown->data >= 0)
        {
            newNumber.addFront(tmpUp->data - tmpDown->data);
        }
        else
        {
            if(tmpUp->previous->data > 0)
            {
                tmpUp->previous->data--;
                newNumber.addFront(tmpUp->data+10 - tmpDown->data);
            }
            else
            {

                Node * prev = tmpUp->previous;
                while(prev->data == 0)
                {
                    prev->data = 9;
                    prev = prev->previous;
                }
                prev->data--;
                tmpUp->data += 10;

                newNumber.addFront(tmpUp->data - tmpDown->data);
            }
        }
        tmpUp = tmpUp->previous;
        tmpDown = tmpDown->previous;
    }

    /// adding remaining numbers
    while(tmpUp)
    {
        newNumber.addFront(tmpUp->data);
        tmpUp = tmpUp->previous;
    }

    ///dele all left's 0
    while(newNumber.head->data == 0)
    {
        Node * toDelte = newNumber.head;
        newNumber.head = newNumber.head->next;
        delete toDelte;
    }

    newNumber.printNumber();
    return newNumber;
}


ostream & operator<<(ostream& os, LongNumber & ln)
{
    ln.printNumber();
    return os;
}

void LongNumber::printNumber()
{
    //cout<<"digit = ("<<digit<<")"<<endl;
    if(sign == -1) cout<<"-";
    Node * tmp = head;
    while(tmp)
    {
        cout<<tmp->data;
        tmp = tmp->next;
    }
    /*Node * tmp = tail;
    while(tmp)
    {
        cout<<tmp->data;
        tmp = tmp->previous;
    }*/
}

