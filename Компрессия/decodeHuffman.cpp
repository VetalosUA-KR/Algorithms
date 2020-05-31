#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    map<char, vector<bool> > table;

    string line;
    ifstream in("kode.txt");

    if(in.is_open())
    {
        while(getline(in, line))
        {
            cout<<"symbol = "<<line[0]<<"  kode = [";
            for(int i = 2; i < line.length(); i++)
            {
                cout<<line[i];
            }
            cout<<"]";
            cout<<endl;
        }
    }

    in.close();

    return 0;
}
