#include <fstream>
#include <vector>

using namespace std;

using Edge = int;
struct Vertex{
    vector<Edge> in;
    vector<Edge> out;
    void push_out(Edge e)
    {
        out.push_back(e);
    }
    int size_out() const
    {
        return out.size();
    }

    void push_in(Edge e)
    {
        in.push_back(e);
    }
    int size_in() const
    {
        return in.size();
    }
};
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
            if(t)
            {
                g[i].push_out(j);
                g[j].push_in(i);
            }
        }
    }


    for(Vertex const& v : g)
    {
        cout<<v.size_in()<<" "<<v.size_out()<<"\n";
    }

    return 0;
}
