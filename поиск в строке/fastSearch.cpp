#include <iostream>
#include <fstream>
#include <bitset>
#include <climits>

using namespace std;

int main()
{
    /*
    fstream fs("0101.txt", ios::in | ios::binary);

    char temp;
    string qq;
    while(fs.read(&temp, sizeof(char)))
    {
        //cout<<(bool)temp<<" ";
        cout<<bitset<sizeof(temp) * CHAR_BIT>(temp)<<" ";
        //q = (char)bitset<sizeof(temp) * CHAR_BIT>(temp);
    }
    */

    fstream fs("0101.txt", ios::in | ios::binary);

    char temp;
    string qq;
    while(fs.read(&temp, sizeof(char)))
    {
        //cout<<(bool)temp<<" ";
        for(int i = (sizeof(temp) * CHAR_BIT)-1; i >= 0 ; --i)
        {
            cout<<((temp>>i) &1)<<" ";
            if(((temp>>i) &1) == 0) qq += "0";
            if(((temp>>i) &1) == 1) qq += "1";

        }

        //q = (char)bitset<sizeof(temp) * CHAR_BIT>(temp);
    }

    cout<<endl<<"*********"<<endl<<qq;
    return 0;
}
