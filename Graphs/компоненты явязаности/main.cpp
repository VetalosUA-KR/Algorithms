#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");

    int n,m;
    cin>>n>>m;
    bool matrix[n][n] {};
    while(m--)
    {
        int from, to;
        cin>>from>>to;
        --from, --to;
        matrix[from][to] = matrix[to][from] = 1;
    }

    for(int i = 0; i < n; ++i)
    {
        matrix[i][i] = 1;
    }

    for(int transit = 0; transit < n; ++transit)
    {
        for(int from = 0; from < n; ++from)
        {
            for(int to = 0; to < n; ++to)
            {
                matrix[from][to] = matrix[from][to] ||
                                   matrix[from][transit] && matrix[transit][to];
            }
        }
    }

    bool used[n] {};
    vector<vector<int> > r;
    for(int i = 0; i < n; ++i)
    {
        if(!used[i])
        {
            vector<int> link;
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j])
                {
                    used[j] = 1;
                    link.push_back(j);
                }
            }
            r.push_back(link);
        }
    }
    cout<<r.size()<<"\n";
    for(auto const& link : r)
    {
        cout<<link.size()<<"\n";
        for(auto l : link)
        {
            cout<<l+1<<" ";
        }
        cout<<"\n";
    }


    return 0;
}










