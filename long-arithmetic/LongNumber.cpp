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
    head->setDigit(d);
    tail = head;
    for(; i < strlen(number); i++)
    {
        addElement(number[i]);
    }
}

LongNumber::LongNumber()
{
    head = new Node('0'); /** ****************************************************************************************************/
    head->setDigit(10);
}

LongNumber::LongNumber(LongNumber & ln)
{
    while(head != nullptr)
    {
        Node * toDel = head;
        head = head->next;
        delete toDel;
        size--;
    }
    tail = nullptr;

    /// add new
    head = new Node(ln.getHead()->data);
    head->setDigit(ln.getHead()->getDigit());
    tail = head;
    Node * current = ln.getHead()->next;
    for(int i = 1; i <= ln.getSize(); i++)
    {
        addElement(current->data);
        current = current->next;
    }
}

LongNumber::~LongNumber()
{
    while(head)
    {
        Node * toDelete = head;
        head = head->next;
        delete toDelete;
    }
    tail = nullptr;
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
    tmp->next->previouse = tmp;
    tail = newElement;
    size++;
}

LongNumber & LongNumber::operator = (LongNumber & ln)
{
    /// if the same
    if(this == &ln) return * this;
    ///dele old
    while(head != nullptr)
    {
        Node * toDel = head;
        head = head->next;
        delete toDel;
        size--;
    }
    tail = nullptr;

    /// add new
    this->head = new Node(ln.getHead()->data);
    this->head->setDigit(ln.getHead()->getDigit());
    Node * current = ln.getHead()->next;
    while(current)
    {
        addElement(current->data);
        current = current->next;
    }
    return *this;
}



bool helpOperator(LongNumber & left, LongNumber & right)
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
bool LongNumber::operator < ( LongNumber & ln)
{
    return (helpOperator(*this, ln));
}
bool LongNumber::operator > ( LongNumber & ln)
{
    return !(helpOperator(*this, ln));
}


ostream & operator <<(ostream & os, LongNumber & ln)
{
    ln.printNumber();
    ///cout<<endl<<"digit = "<<ln.getHead()->getDigit()<<endl;
    return os;
}

istream & operator >>(istream & is, const LongNumber & ln)
{

}

LongNumber & LongNumber::operator+(LongNumber & ln)
{
    /*LongNumber tmp;

    tmp.getHead()->setDigit(head->getDigit());

    Node * tmpUp = tail;
    Node * tmpDown = ln.getTail();

    int upNumber;
    int downNumber;

    char rez;

    while(tmpUp->previouse && tmpDown->previouse)
    {
        upNumber = tmpUp->data-'0';
        downNumber = tmpDown->data-'0';
        rez = (upNumber+downNumber)+'0';

        tmp.pushBack(rez);
        tmpUp = tmpUp->previouse;
        tmpDown = tmpDown->previouse;
    }*/
    /**tmp.head->previouse = new Node('+');
    tmp.head->previouse->next = tmp.head;
    tmp.head = tmp.head->previouse;
    tmp.head->previouse->setDigit(head->getDigit());*/
    /*Node * ne = new Node('+');
    tmp.head->previouse = ne;
    tmp.head->previouse->next = tmp.getHead();
    tmp.head = ne;
    //cout<<"head = "<<tmp.head->next->data<<endl;
    tmp.printNumber();
    return tmp;*/

    //cout<<head->data;
    LongNumber dumm;
    /*dumm.head->data = head->data;
    dumm.head->setDigit(head->getDigit());*/
    Node * tmpUp = tail;
    Node * tmpDown = ln.getTail();
    int carr = 0;
    while(tmpUp->previouse)
    {
        int upNumber =   (tmpUp   != nullptr) ? tmpUp->data-'0' : 0;
        int downNumber = (tmpDown != nullptr) ? tmpDown->data-'0' : 0;
        int sum = upNumber + downNumber;
        cout<<" upNumber = "<<upNumber;
        cout<<"\t downNumber = "<<downNumber;
        cout<<"\t sum = "<<sum<<endl;
        carr = sum / (ln.getHead()->getDigit());
        char rez = ((upNumber+downNumber) % (ln.getHead()->getDigit()))+'0';
        dumm.pushBack(rez);
        tmpUp = tmpUp->previouse;
        tmpDown = tmpDown->previouse;
        if(carr > 0)
        {
            rez = carr+'0';
            dumm.pushBack(rez);
        }

        cout<<endl;
    }
    /*Node * ne = new Node('+');
    dumm.head->previouse = ne;
    dumm.head->previouse->next = dumm.getHead();
    dumm.head = ne;*/
    //cout<<dumm.head->data<<endl;
    //dumm.head->data = '+';
dumm.printNumber();

    return dumm;
}


void LongNumber::pushBack(char n)
{
    /*if(head->data != '0')
    {
        head->chagneData(n);
    }
    else
    {*/
    //if(head->previouse)cout<<"old data = "<<head->previouse->data<<endl;

    /// for first's element

        if(head->data == '0')
        {
            head->chagneData(n);
        }
        else
        {
            head->previouse = new Node(n);
            head->previouse->next = head;
            head = head->previouse;
            //head->chagneData(n);
            size++;
        }

    //}
}

void LongNumber::pushBack2(char n)
{
    head->previouse = new Node(n);
    head->previouse->next = head;
    //head = head->previouse;

    size++;
}

void LongNumber::printNumber()
{
    Node * tmp = head;
    while(tmp)
    {
        //if(tmp->data != '+')
            cout<<tmp->data;
        tmp = tmp->next;
    }
    /**Node * tmp = tail;
    while(tmp != head->previouse)
    {
        cout<<tmp->data;
        tmp = tmp->previouse;
    }*/
}











