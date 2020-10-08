#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#define edg pair<int,int>
class Kruskal
{
private:
    class Graph
    {
    private:
        vector<pair<float, edg>> G; // graph
        vector<pair<float, edg>> T; // mst
        int *parent;
        int V; // number of vertices/nodes in graph
    public:
        Graph(int V)
        {
            parent = new int[V];
            for (int i = 0; i < V; i++)
                parent[i] = i;

            G.clear();
            T.clear();
        }
        void AddWeightedEdge(int u, int v, float w)
        {
            G.push_back(make_pair(w, edg(u, v)));
        }
        int find_set(int i)
        {
            if (i == parent[i])
            {
                return i;
            }
            else
                return find_set(parent[i]);
        }

        void union_set(int u, int v)
        {
            parent[u] = parent[v];
        }
        void kruskal()
        {
            int i, uRep, vRep;
            sort(G.begin(), G.end()); // increasing weight
            for (i = 0; i < G.size(); i++)
            {
                uRep = find_set(G[i].second.first);
                vRep = find_set(G[i].second.second);
                if (uRep != vRep)
                {
                    T.push_back(G[i]); // add to tree
                    union_set(uRep, vRep);
                }
            }
        }
        void print()
        {
            ofstream write;
            write.open("src/MST_Adjacencies.txt");
            for (int i = 0; i < T.size(); i++)
            {
                write << T[i].second.first << " " << T[i].second.second << " "
                     << T[i].first;
                write << "\n";
            }
        }
    };
public:
    void makeMSTKruskal()
    {
        ifstream roz;
        roz.open("src/matrix.txt");
        int r;
        roz>>r;
        roz.close();

        Graph g(r+1);
        ifstream fin;
        fin.open("src/AllAdjacencies.txt");
        string str;
        while(!fin.eof())
        {
            int u,v;
            float w;
            fin>>u>>v>>w;
            //cout<<"["<<x<<"] ["<<y<<"] ["<<w<<"]"<<endl;
            g.AddWeightedEdge(u, v, w);
        }
        g.kruskal();
        g.print();
    }
};
