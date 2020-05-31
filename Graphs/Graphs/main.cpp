#include <iostream>
#include "AdjacencyList.h"
#include "Graph.h"
#include "matrix.h"
#include <fstream>

using namespace std;

void connectWithCapital()
{
    ifstream roz;
    roz.open("src/mst_matrix.txt");
    int size;
    roz>>size;

    ifstream in;
    in.open("src/AllAdjacencies.txt");
    for(int i = 0; i < size; i++)
    {

    }

}

int main()
{
    //Using the matrix.txt file, create the AllAdjacency.txt file, in which we save the arcs of all the vertices
    AdjacencyList al;
    al.createAdjacencyList();

    //Creating Minimum Spanning Tree using algorithm Kruskal’s
    Kruskal g;
    g.makeMSTKruskal();

    //Creating new matrix, used mst
    Matrix m;
    m.createMatrix();

    /*ifstream f;
    string str = "";
    f.open("src/test.txt");
    while(!f.eof())
    {
        getline(f, str);
    }
    cout<<endl<<str;*/


    return 0;
}








