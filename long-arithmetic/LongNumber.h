#ifndef LN_H
#define LN_H
#include <iostream>


using namespace std;

class LongNumber
{
private:
    struct Node
    {
    private:
        int digit = 0;
    public:
        char data;
        Node * next;
        Node * previouse;
        Node (char d = '0', Node * n = nullptr)
        {
            data = d;
            next = n;
        }
        void setDigit(int d){ digit = d; }
        int getDigit(){ return digit; }
        void chagneData(char d)
        {
            cout<<"data = "<<data<<"\t d = "<<d<<endl;
            int rez = (data-'0')+(d-'0');
            char newData = rez+'0';
            data = newData;
        }
    };

    int size = 0;
    Node * head = nullptr;
    Node * tail = nullptr;

    void addElement(char n);
    void pushBack(char n);
    void pushBack2(char n);

public:

    LongNumber (char * number, int d);
    LongNumber (LongNumber & ln);
    LongNumber ();
    ~LongNumber();

    void printNumber();
    bool operator < ( LongNumber & ln) ;
    bool operator > ( LongNumber & ln) ;
    friend bool helpOperator(LongNumber & left, LongNumber & right);

    friend ostream & operator <<(ostream & os, LongNumber & ln);
    friend istream & operator >>(istream & is, const LongNumber & ln);
    LongNumber & operator = (LongNumber & ln);
    LongNumber & operator + (LongNumber & ln);

    int getSize(){ return size; }
    Node * getHead(){ return head; }
    Node * getTail(){ return tail; }
};




#endif // LN_H
