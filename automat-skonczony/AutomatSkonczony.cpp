#include <iostream>
#include <cstring>

using namespace std;

int PrefixSufix(char *t1, int k, char *t2, int k2)
{
    int d = min(k, k2);
    cout<<"PS d="<<d<<endl;
    while(d > 0)
    {
        int found = 1;
        for(int i = 0; i < d; i++)
        {
            if(t1[k-d+i] != t2[i])
            {
                found = 0;
                break;
            }
        }
        if(found) return d;
        d--;
    }
    return 0;  //  <-----------  TUTAJ
}

int main()
{
    char * text="abbbabbcbbbcb";
    char * wzorz="cbb";

    cout<<"Testowo : PrefSuf(cba,3,cbb,3) = "<<PrefixSufix("cba",3,"cbb",3)<<endl;

    int n = strlen(text);
    int m = strlen(wzorz);
    char * s = new char [100];

  cout<<n<<"---"<<m<<endl;
    int (*a)[3] = new int [m+1][3];
    char * alfabet = "abc";

    cout<<alfabet[2]<<endl;
    cout<<"m="<<m<<endl<<endl;


    for(int i = 0; i <=m; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            //char * s = new char[i+1];
            for(int t = 0; t < i; t++)
            {
                s[t] = wzorz[t];
            }
            cout<<"ostatnia litera "<<(s[i] = alfabet[j])<<endl;
            s[i+1] = 0;
         cout<<s<<endl;
            a[i][j] = PrefixSufix(s, i+1, wzorz, m);
        }
    }

for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }







    int stan = 0;
    for(int i = 0; i < n; i++)
    {
        stan = a[stan][text[i]-'a'];

        if(stan == m) cout<<"znalazlem wzorzec "<<i-m+1<<endl;
    }




    return 0;
}




