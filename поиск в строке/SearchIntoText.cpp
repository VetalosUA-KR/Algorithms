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

string getBitsFromFile(string fileName)
{
    fstream fs(fileName, ios::in | ios::binary);
    char temp;
    string str;
    while(fs.read(&temp, sizeof(char)))
    {
        for(int i = (sizeof(temp) * CHAR_BIT)-1; i >= 0 ; --i)
        {
            if(((temp>>i) &1) == 0) str += "0";
            if(((temp>>i) &1) == 1) str += "1";

        }
    }
    return str;
}

string getToString(string fileName)
{
    ifstream fin;
    fin.open(fileName);
    string all;
    if(!fin.is_open())
    {
        cout<<"can't open file"<<endl;
    }
    else
    {
        string str;
        while(!fin.eof())
        {
            str="";
            getline(fin, str);
            all += str;
            all += "\n";
        }

    }
    fin.close();
    return all;
}

///     Naive
int searchNaive(string str, string strSample)
{
    int proba = 0;
    for(int i = 0; i < str.length(); i++)
    {
        int j = 0;
        proba++;
        while(j < strSample.length() && i + j < str.length() && strSample[j] == str[i+j])
        {
            proba++;
            j++;
        }
        if(j == strSample.length())
        {
            //cout<<"FIND \t start ["<<(i+j)-strSample.length()<<"] end ["<<i+j<<"]"<<endl;
        }
    }
    return proba;
}

///     Knuth Morris Pratt
int * prefixFunction(string sample, int &sp)
{
    int *values = new int[sample.length()];
    for(int i = 0; i < sample.length(); i++)
        values[i] = 0;

    for(int i = 1; i < sample.length(); i++)
    {
        int j = 0;
        while(i + j < sample.length() && sample[j] == sample[i+j])
        {
            values[i+j] = max(values[i+j], j+1);
            j++;
        }
    }
    sp = sample.length();
    return values;
}
int KMPSearch(string text, string sample)
{
    int sizePrefix;
    int *prefixFun = prefixFunction(sample, sizePrefix);

    int i = 0;
    int j = 0;
    int proba = 0;
    while(i < text.length())
    {
        if(sample[j] == text[i])
        {
            proba++;
            j++;
            i++;
        }
        if(j == sample.length())
        {
            //cout<<"FIND \t start ["<<(i-j)<<"] end ["<<(i-j)+sample.length()<<"]"<<endl;
            j = prefixFun[j-1];
            proba -= j;
        }
        else if(i < text.length() && sample[j] != text [i])
        {
            proba++;
            if(j != 0)
            {
                j = prefixFun[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    //cout<<endl<<"KMPilosc prob = "<<proba<<endl;
    return proba;
}

///     Rabin-Karp
int RKSearch(string txt, string pat)
{
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int proba = N-M;
    int q = 101;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if ( p == t )
        {
            for (j = 0; j < M; j++)
            {
                proba++;
                if (txt[i+j] != pat[j])
                    break;
            }
            if (j == M)
            {
                //cout<<"FIND \t start ["<< i<<"]  end ["<<i+M<<"]"<<endl;
            }
        }
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
            if (t < 0)
            t = (t + q);
        }
    }
    //cout<<endl<<"RK ilosc prob = "<<proba<<endl;
    return proba;
}

///     Boyer Moore
void badCharHeuristic( string str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

int BMSearch( string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
    int proba = 0;

    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while(s <= (n - m))
    {
        int j = m - 1;
        while(j >= 0 && pat[j] == txt[s + j])
        {
            j--;
            proba++;
        }

        if (j < 0)
        {
            //cout << "FIND \t start ["<<s<<"] end ["<<s+m<<"]"<<endl;
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
        }
        else
        {
            s += max(1, j - badchar[txt[s + j]]);
            proba++;
        }
    }
    //cout<<endl<<"BM ilosc prob = "<<proba<<endl;
    return proba;
}

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
    srand(time(0));
    string txt = getBitsFromFile("robinson_crusoe2.txt");
    cout<<"length txt = "<<txt.length()<<endl;
    string pattern;
    int lengthPattern[6] = {3,5,10,50,1000,5000};

    unsigned long long naiveS = 0,KMPS = 0,RKS = 0,BMS = 0;

    int iloscTestow = 100;

    for(int i = 0; i < 6; i++)
    {
        cout<<"****************************************"<<endl<<"\t lenght of pattern = "<<lengthPattern[i]<<endl<<endl;
        for(int j = 0; j < iloscTestow; j++)
        {
            pattern = getPartText(txt, lengthPattern[i]);
            //pattern = "1111";

            naiveS += searchNaive(txt, pattern);
            KMPS += KMPSearch(txt, pattern);
            RKS += RKSearch(txt, pattern);
            BMS += BMSearch(txt, pattern);
        }
        cout<<"ilosc prob metody [Naive] = "<<naiveS/iloscTestow<<endl;
        cout<<"ilosc prob metody [KMPS]  = "<<KMPS/iloscTestow<<endl;
        cout<<"ilosc prob metody [RKS]   = "<<RKS/iloscTestow<<endl;
        cout<<"ilosc prob metody [BMS]   = "<<BMS/iloscTestow<<endl;
        naiveS = KMPS = RKS = BMS = 0;
        cout<<endl;
    }

    return 0;
}







