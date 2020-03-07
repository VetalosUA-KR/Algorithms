#include <iostream>
#include <cstring>

using namespace std;

int DNWP(char * p, int dp, char * q, int dq)
{
    if(dp*dq == 0)
    {
        return 0;
    }
    if(p[dp-1] == q[dq-1]) return DNWP(p, dp-1, q, dq-1)+1;
    return max(DNWP(p, dp-1, q, dq), DNWP(p, dp, q, dq-1));
}

int DNWP2(char * p, int dp, char * q, int dq)
{
    int (*tab)[100] = new int [100][100];
    for(int i = 0; i <= dp; i++)
    {
        for(int j = 0; j <= dq; j++)
        {
            tab[i][j] = 0;
            if(i*j == 0) tab[i][j] = 0;
            else if(p[i-1] == q[j-1]) tab[i][j] = tab[i-1][j-1]+1;
            else tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
        }
    }

    for(int i = 0; i <= dp; i++)
    {
        for(int j = 0; j <= dq; j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }

    return tab[dp][dq];
}

int ol(char * p, int dp, char * q, int dq)
{
    int (*tab)[100] = new int [100][100];
    for(int i = 0; i <= dp; i++)
    {
        for(int j = 0; j <= dq; j++)
        {
            int cost = 1;
            if(p[i-1] == q[j-1]) cost = 0;
            if(i == 0) tab[i][j] = j;
            else if(j == 0) tab[i][j] = i;
            else tab[i][j] = (tab[i][j-1]+1 < tab[i-1][j]+1) ? min(tab[i][j-1]+1,tab[i-1][j-1]+cost)  : min(tab[i-1][j]+1, tab[i-1][j-1]+cost)  ;
        }
    }
    for(int i = 0; i <= dp; i++)
    {
        for(int j = 0; j <= dq; j++)
        {
            cout<<tab[i][j]<<"   ";
        }
        cout<<endl;
    }

    return tab[dp][dq];
}

///odleglosc levenshteina
int main()
{

    char * c1 = "piecyk";
    char * c2 = "opiec";
    cout<<ol(c1, strlen(c1), c2, strlen(c2));

    return 0;
}
