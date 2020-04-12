#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>

using namespace std;

class Node
{
public:
    int number;
    char symbol = '\0';
    Node * left;
    Node * right;

    Node (){left=right=nullptr;}
    Node(Node *L, Node *R)
    {
        left = L;
        right = R;
        number = L->number + R->number;
    }
};

/**
to zrobione dlatego zeby dzialala metoda sort() na listê
mozno to bylo zrobic takoz przez przeciazenie operatora < w klasie Node
*/
struct MyCompare
{
    bool operator()(Node* l, Node* r) const
    {
        return l->number < r->number;
    }
};

void print(Node * root, unsigned k=0)
{
    if(root != nullptr)
    {
        print(root->left, k+3);
        for(unsigned i = 0; i < k; i++)
        {
            cout<<"   ";
        }
        if(root->symbol) cout<<root->number<<" ("<<root->symbol<<")"<<endl;
        else cout<<root->number<<endl;
        print(root->right, k+3);
    }
}

vector<bool> code;
map<char, vector<bool> > table;
void buildTable(Node *root)
{
    if(root->left)
    {
        code.push_back(0);
        buildTable(root->left);
    }
    if(root->right)
    {
        code.push_back(1);
        buildTable(root->right);
    }
    if(root->symbol)
    {
        table[root->symbol] = code;
    }
    code.pop_back();
}


int main ()
{
    string s = "hello my name is Vitalii Voitenko, this is test string line";
    cout<<s<<endl;

    map<char, int> m;
    for(int i = 0; i < s.length(); i++)
    {
        char symbol = s[i];
        m[symbol]++;
    }

    list<Node*> nodeList;

    map<char, int>::iterator i;
    for(i = m.begin(); i != m.end(); ++i)
    {
        cout<<i->first<<" : "<<i->second<<endl;
        Node * currentNode = new Node();
        currentNode->symbol = i->first;
        currentNode->number = i->second;
        nodeList.push_back(currentNode);
    }

    while(nodeList.size() != 1)
    {
        nodeList.sort(MyCompare());

        Node *SonL = nodeList.front();
        nodeList.pop_front();
        Node *SonR = nodeList.front();
        nodeList.pop_front();

        Node *parent = new Node(SonL, SonR);
        nodeList.push_back(parent);
    }

    cout<<endl;
    cout<<endl;
    Node *root = nodeList.front();
    print(root,0);

    cout<<endl;
    buildTable(root);

    map<char, vector<bool> >::iterator iter;
    for(iter = table.begin(); iter != table.end(); ++iter)
    {
        cout<<iter->first<<" : ";
        for(int l = 0; l < iter->second.size(); l++)
        {
            cout<<iter->second[l];
        }
        cout<<endl;
    }


    return 0;
}









