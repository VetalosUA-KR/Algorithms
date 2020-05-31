#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#define edge pair<int,int>
class Kruskal
{
private:
    class Graph
    {
    private:
        vector<pair<float, edge>> G; // graph
        vector<pair<float, edge>> T; // mst
        int *parent;
        int V; // number of vertices/nodes in graph
    public:
        /*Graph(int V);
        void AddWeightedEdge(int u, int v, int w);
        int find_set(int i);
        void union_set(int u, int v);
        void kruskal();
        void print();*/
        Graph(int V)
        {
            parent = new int[V];

            //i 0 1 2 3 4 5
            //parent[i] 0 1 2 3 4 5
            for (int i = 0; i < V; i++)
                parent[i] = i;

            G.clear();
            T.clear();
        }
        void AddWeightedEdge(int u, int v, float w)
        {
            G.push_back(make_pair(w, edge(u, v)));
            //cout<<"u: "<<u<<"\t v: "<<v<<endl;
        }
        int find_set(int i)
        {
            //cout<<"i: "<<i<<endl;
            // If i is the parent of itself
            if (i == parent[i])
            {
                //cout<<"exit I: "<<i<<endl;
                return i;
            }
            else
                // Else if i is not the parent of itself
                // Then i is not the representative of his set,
                // so we recursively call Find on its parent
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
            //cout << "Edge :" << " Weight" << endl;
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
