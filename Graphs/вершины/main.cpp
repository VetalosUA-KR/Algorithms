#include <fstream>
#include <vector>

using namespace std;

using Edge = int;
using Vertex = vector<Edge>;
using Graph = vector<Vertex>;

Graph g;

int main ()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n;
    cin>>n;
    g.resize(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            bool t;
            cin>>t;
            if(t) g[i].push_back(j);
        }
    }


    for(Vertex const& v : g)
    {
        cout<<v.size()<<" ";
    }

    return 0;
}
