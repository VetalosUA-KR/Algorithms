#include <fstream>
#include <vector>
#include <iostream>
#include <cmath>
# define M_PI           3.14159265358979323846

using namespace std;


class AdjacencyList
{
private:
    using Edge = int;
    using Vertex = vector<Edge>;
    using Graph = vector<Vertex>;

    Graph g;

public:
    void createAdjacencyList()
    {
        ifstream fin;
        fin.open("src/miasta.txt");
        string str;

        ifstream roz;
        roz.open("src/matrix.txt");
        int r;
        roz>>r;
        roz.close();
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

        ofstream cout("src/AllAdjacencies.txt");
        ifstream cin("src/matrix.txt");
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
        cout.close();
    }
};
