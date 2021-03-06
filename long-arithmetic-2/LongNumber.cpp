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
    size++;
}


void LongNumber::addFront2(int d)
{
    Node * newElement = new Node(d);
    head->previous = newElement;
    newElement->next = head;
    size++;
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

LongNumber LongNumber::operator*(LongNumber& ln)
{
    LongNumber newNumber;
    newNumber.addFront(0);

    LongNumber osnovnoe;
    Node * tmpUp = tail;
    Node * tmpDown = ln.tail;

    osnovnoe = (*this > ln) ? *this : ln;
    if(*this > ln)
    {
        osnovnoe = ln;
        tmpUp = tail;
        tmpDown = ln.tail;
    }
    else
    {
        osnovnoe = *this;
        tmpUp = ln.tail;
        tmpDown = tail;
    }
    LongNumber helpArr[osnovnoe.size];


    for(int i = 0; i < osnovnoe.size; i++)
    {
        LongNumber tmp;
        for(int j = 0; j < i; j++)
        {
            tmp.addFront(0);
        }
        Node * _tmpUp = tmpUp;
        while(_tmpUp)
        {
            int upNumber = (_tmpUp != nullptr) ? _tmpUp->data : 0;
            int downNumber = (tmpDown != nullptr) ? tmpDown->data : 0;
            int mod = (upNumber * downNumber) / ln.digit;
            tmp.addFront((upNumber * downNumber) % ln.digit);
            if(mod > 0)
            {
                tmp.addFront2(mod);
            }
            if(_tmpUp)_tmpUp = _tmpUp->previous;
        }
        if(tmpDown)tmpDown = tmpDown->previous;

        while(tmp.head->previous != nullptr)
        {
            tmp.head = tmp.head->previous;
        }
        helpArr[i] = tmp;
    }

    for(int i = 0; i < osnovnoe.size; i++)
    {
        newNumber = newNumber + helpArr[i];
    }
    if(sign == -1 ^ ln.sign == -1) newNumber.sign = -1;
    else newNumber.sign = 1;
    return newNumber;
}

LongNumber LongNumber::operator/(LongNumber& ln)
{
    LongNumber tmpLessNumber;
    LongNumber tmpLongNumber;
    if(*this > ln)
    {
        tmpLessNumber = ln;
        tmpLongNumber = *this;
    }
    else
    {
        tmpLessNumber = *this;
        tmpLongNumber = ln;
    }


    LongNumber divider("1", 10);

    LongNumber tmp = tmpLessNumber;
    while(tmpLongNumber > tmp)
    {
        divider++;
        tmp = tmp + tmpLessNumber;
    }
    return divider;
}

LongNumber& LongNumber::operator++(int)
{
    Node * tmp = tail;
    int tmpNumer = tmp->data;
    while(tmpNumer++ >= digit-1)
    {
        if(tmp->previous)
        {
            tmp->data = 0;
            tmp = tmp->previous;
            tmpNumer = tmp->data;
        }
        else
        {
            addFront(0);
            tmp->data = 0;
        }
    }
    tmp->data++;
    return *this;
}


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

    LongNumber left = *this;
    LongNumber right = ln;
    if(left.sign == -1 || right.sign == -1)
    {
        if(left > right)
        {
            right.sign = 1;
            newNumber = right - left;
            if(right > left) newNumber.sign = -1;
            else newNumber.sign = 1;
        }
        else
        {
            left.sign = 1;
            newNumber = left - right;
            if(left > right) newNumber.sign = -1;
            else newNumber.sign = 1;
        }
    }
    return newNumber;
}

LongNumber LongNumber::operator-(LongNumber& ln2)
{
    LongNumber right = ln2;
    LongNumber left = *this;

    LongNumber newNumber;
    Node * tmpUp = left.tail;
    Node * tmpDown = right.tail;
    ///if left is negative and right is positive
    if(left.sign == -1 && right.sign != -1)
    {
        newNumber = right + left;
        newNumber.sign = -1;
        return newNumber;
    }
    ///if right is negative and left is positive
    if(right.sign == -1 && left.sign != -1)
    {
        newNumber = right + left;
        newNumber.sign = 1;
        return newNumber;
    }
    ///if both numbers is negative
    if(left.sign == -1 && right.sign == -1)
    {
        if(left == right)
        {
            newNumber.addFront(0);
            newNumber.sign = 1;
        }
        if(left > right)
        {

            left.sign = 1;
            right.sign = 1;
            helpOdejmovanie(right, left, newNumber);
            newNumber.sign = 1;
        }
        else
        {
            left.sign = 1;
            right.sign = 1;
            helpOdejmovanie(left, right, newNumber);
            newNumber.sign = -1;
        }
    }
    else
    {
        newNumber = left + right;
        newNumber.sign = -1;
    }
    return newNumber;
}

void helpOdejmovanie(LongNumber & left, LongNumber & right, LongNumber & newNumber)
{
    LongNumber::Node * tmpUp = left.tail;
    LongNumber::Node * tmpDown = right.tail;
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
                LongNumber::Node * prev = tmpUp->previous;
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
        LongNumber::Node * toDelte = newNumber.head;
        newNumber.head = newNumber.head->next;
        delete toDelte;
    }
}

ostream & operator<<(ostream& os, LongNumber & ln)
{
    ln.printNumber();
    return os;
}

istream & operator>>(istream& is, LongNumber & ln)
{
    cout<<"podaj liczbu -> ";
    string licz;
    int digit;

    is>>licz;
    cout<<"podaj rozriad -> ";
    is>>digit;
    LongNumber newNumber(licz, digit);
    ln = newNumber;
    return is;
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

