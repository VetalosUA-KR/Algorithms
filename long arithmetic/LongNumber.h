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
        Node (char d, Node * n = nullptr)
        {
            data = d;
            next = n;
        }
        void setDigit(int d){ digit = d; }
        int getDigit(){ return digit; }
    };

    int size = 0;
    Node * head = nullptr;
    //Node * tail = nullptr;

    void addElement(char n);

public:

    LongNumber(char * number, int d);
    ~LongNumber();
    void printNumber();
    bool operator < (const LongNumber ln) const;
    bool operator > (const LongNumber ln) const;
    friend bool helpOperator(LongNumber left, LongNumber right);

    friend ostream & operator <<(ostream & os, LongNumber & ln);
    friend istream & operator >>(istream & is, const LongNumber & ln);
    LongNumber & operator = (const LongNumber & ln);

    int getSize(){ return size; }
    Node * getHead(){ return head; }
};




#endif // LN_H
