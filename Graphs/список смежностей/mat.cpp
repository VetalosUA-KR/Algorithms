#include <fstream>
#include <vector>
#include <iostream>
#include <cmath>
# define M_PI           3.14159265358979323846

using namespace std;

using Edge = int;
using Vertex = vector<Edge>;
using Graph = vector<Vertex>;

Graph g;

int main ()
{
    ifstream fin;
    fin.open("miasta.txt");
    string str;

    ifstream roz;
    roz.open("input.txt");
    int r;
    roz>>r;
    roz.close();
    cout<<"rozmier = "<<r<<endl;
    float arr[r][2] {};
    int i = 0;
    while(!fin.eof())
    {
        str="";
        getline(fin, str);
        int px = str.find(" ");
        string posX = str.substr(0, px);
        string posY = str.substr(px+1, str.find(" "));
        float x = stof(posX);
        float y = stof(posY);
        arr[i][0] = x;
        arr[i][1] = y;
        i++;
    }
    for(int q = 0; q < 17; q++)
    {
        for(int l = 0; l < 2; l++)
        {
            cout<<arr[q][l]<<" ";
        }
        cout<<endl;
    }

    ofstream cout("output.txt");
    ifstream cin("input.txt");
    int n;
    cin>>n;
    g.resize(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            bool t;
            cin>>t;
            if(t)
                g[i].push_back(j);
        }
    }

    for(int i = 0; i < g.size(); i++)
    {
        for(int j = 0; j < g[i].size(); j++)
        {
            float w = sqrt( pow((arr[g[i][j]][0] - arr[i][0]), 2) + pow(cos((arr[i][0]*M_PI)/180.0) * (arr[g[i][j]][1] - arr[i][1]), 2) ) * 4075.704/360;
            cout<<i + 1<<" "<<g[i][j]+1<<" "<<w<<"\n";
        }
    }
    return 0;
}

