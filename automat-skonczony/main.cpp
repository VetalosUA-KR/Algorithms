#include <iostream>
#include <cstring>

using namespace std;

int PrefixSufix(char *t1, int k, char *t2, int k2)
{
    int d = min(k, k2);
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
    return 0;
}

int main()
{
    /*char * text = "acbaccbcacbacccacb";
    char * wzorz = "bacc";
    int tab [5][3] = {{0,1,0}, {2,1,0}, {0,1,3}, {0,1,4}, {0,1,0}};// zachyfrowany wzorzec

    int n = strlen(text);
    int m = strlen(wzorz);

    int stan = 0;
    for(int i = 0; i < n; i++)
    {
        stan = tab[stan][text[i]-'a'];

        if(stan == m) cout<<"znalazlem wzorzec "<<i-m+1<<endl;
    }


    char * text1 = "baoba";
    char * text2 = "bay";
    cout<<PrefixSufix(text1, strlen(text1), text2, strlen(text2));*/
    char * text="abbbabbcbbbcb";
    char * wzorz="cab"; // = new char [100];
    int n = strlen(text);
    int m = strlen(wzorz);
    char * s = new char [100];

    int (*a)[3] = new int [m+1][3];
    char * alfabet = "abc";

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            //char * s = new char[i+1];
            for(int t = 0; t < i; t++)
            {
                s[t] = wzorz[t];
            }
            s[i] = alfabet[j];
            s[i+1] = 0;
         cout<<s<<endl;
            a[i][j] = PrefixSufix(s, i, wzorz, m);
        }
    }

for(int i = 0; i <= 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}




