#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <vector>

using namespace std;

const string patt[] {"NO\n", "YES\n"};

/*int main ()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        bool g[n][n]{};
        bool doubleEdge = false;
        while(m--)
        {
            int from, to;
            cin>>from>>to;
            --from, --to;
            if(g[from][to]) doubleEdge = true;
            g[from][to] = true;
        }
        cout<<patt[doubleEdge];
    }

    return 0;
}*/
/// без двумерного массива
/*int main ()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        bool g[n*n]{};
        bool doubleEdge = false;
        while(m--)
        {
            int from, to;
            cin>>from>>to;
            --from, --to;
            if(g[from * n + to]) doubleEdge = true;
            g[from * n + to] = true;
        }
        cout<<patt[doubleEdge];
    }

    return 0;
}*/
/// еще вариант

/*bool checkDoubleEdge(int g [], int n)
{
    for(int i = 0; i < n * n; i++)
    {
        if(g[i] > 1) return true;
    }
    return false;
}
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        int g[n * n]{};
        while(m--)
        {
            int from, to;
            cin>>from>>to;
            --from, --to;
            ++g[from * n + to] = true;
        }
        cout<<patt[checkDoubleEdge(g, n)];
    }

    return 0;
}*/




using Edge = int;
using Vertex = vector<Edge>;
using Graph = vector<Vertex>;

using namespace std;

int main ()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        Graph g(n);
        while(m--)
        {
            int from, to;
            cin >> from >> to;
            --from, --to;
            g[from].insert(to);
        }
    }


    return 0;
}









































