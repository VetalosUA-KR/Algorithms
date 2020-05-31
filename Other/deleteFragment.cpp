#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstring>
#include <time.h>

using namespace std;
#define d 256
#define NO_OF_CHARS 256


string getPartText(string txt, int length)
{
    int startPosition = rand()% (txt.size()-length) + 1;
    string rez = "";
    for(int i = startPosition; i < startPosition+length; i++)
    {
        rez += txt[i];
    }
    return rez;
}

int main(void)
{

    ifstream fin;
    fin.open("robinson_crusoe.txt");
    string all;
    if(!fin.is_open())
    {
        cout<<"can't open file"<<endl;
    }
    else
    {
        string str;
        int count = 70000;
        int i = 0;
        while(!fin.eof())
        {
            if(i > count && i < 200000)
            {
                str="";
                getline(fin, str);
                all += str;
                all += "\n";
            }
            else
            {
                getline(fin,str);
            }
        }
        cout<<str.length();
    }

    fin.close();
    return 0;
}







