#include <iostream>
#include "AdjacencyList.h"
#include "Graph.h"
#include "matrix.h"
#include <fstream>
#define INT_MAX 10000000

using namespace std;

void DijkstrasTest(string from, string to);

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

    /// find path between two city
    DijkstrasTest("Szczecin", "Gdansk");

    return 0;
}


class Node;
class Edge;

void Dijkstras();
vector<Node*>* AdjacentRemainingNodes(Node* node);
Node* ExtractSmallest(vector<Node*>& nodes);
int Distance(Node* node1, Node* node2);
bool Contains(vector<Node*>& nodes, Node* node);
void PrintShortestRouteTo(Node* destination);
Node* findByName(string str);

vector<Node*> nodes;
vector<Node*> list_node;
vector<Edge*> edges;

class Node
{
private:
public:
    int size = 0;
    Node(string id)
        : id(id), previous(NULL), distanceFromStart(INT_MAX)
    {
        nodes.push_back(this);
        list_node.push_back(this);
        size++;
    }


public:
    string id;
    Node* previous;
    int distanceFromStart;
};

class Edge
{
public:
    Edge(Node* node1, Node* node2, int distance)
        : node1(node1), node2(node2), distance(distance)
    {
        edges.push_back(this);
    }
    bool Connects(Node* node1, Node* node2)
    {
        return (
                   (node1 == this->node1 &&
                    node2 == this->node2) ||
                   (node1 == this->node2 &&
                    node2 == this->node1));
    }

public:
    Node* node1;
    Node* node2;
    int distance;
};

///////////////////
void DijkstrasTest(string to, string from)
{
    ifstream read;
    read.open("src/miasta.txt");
    while(!read.eof())
    {
        float x,y;
        string str;
        read>>x>>y>>str;
        Node* tmp = new Node(str);
    }
    read.close();

    ifstream ed;
    ed.open("src/MST_Adjacencies.txt");
    while(!ed.eof())
    {
        int x,y;
        float w;
        ed>>x>>y>>w;
        Edge* ed = new Edge(list_node[x-1], list_node[y-1], w);
    }

    cout<<"Distance from "<<to<<" to "<<from<<" = ";
    findByName(from)->distanceFromStart = 0;
    Dijkstras();
    PrintShortestRouteTo(findByName(to));
}

///////////////////

Node* findByName(string str)
{
    for(int i = 0; i < list_node.size(); i++)
    {
        if(list_node[i]->id == str)
        {
            return list_node[i];
        }
    }
    cout<<"Element not founded"<<endl;
    return nullptr;
}

void Dijkstras()
{
    while (nodes.size() > 0)
    {
        Node* smallest = ExtractSmallest(nodes);
        vector<Node*>* adjacentNodes =
            AdjacentRemainingNodes(smallest);

        const int size = adjacentNodes->size();
        for (int i = 0; i < size; ++i)
        {
            Node* adjacent = adjacentNodes->at(i);
            int distance = Distance(smallest, adjacent) +
                           smallest->distanceFromStart;

            if (distance < adjacent->distanceFromStart)
            {
                adjacent->distanceFromStart = distance;
                adjacent->previous = smallest;
            }
        }
        delete adjacentNodes;
    }
}

Node* ExtractSmallest(vector<Node*>& nodes)
{
    int size = nodes.size();
    if (size == 0)
        return NULL;
    int smallestPosition = 0;
    Node* smallest = nodes.at(0);
    for (int i = 1; i < size; ++i)
    {
        Node* current = nodes.at(i);
        if (current->distanceFromStart <
                smallest->distanceFromStart)
        {
            smallest = current;
            smallestPosition = i;
        }
    }
    nodes.erase(nodes.begin() + smallestPosition);
    return smallest;
}

vector<Node*>* AdjacentRemainingNodes(Node* node)
{
    vector<Node*>* adjacentNodes = new vector<Node*>();
    const int size = edges.size();
    for (int i = 0; i < size; ++i)
    {
        Edge* edge = edges.at(i);
        Node* adjacent = NULL;
        if (edge->node1 == node)
        {
            adjacent = edge->node2;
        }
        else if (edge->node2 == node)
        {
            adjacent = edge->node1;
        }
        if (adjacent && Contains(nodes, adjacent))
        {
            adjacentNodes->push_back(adjacent);
        }
    }
    return adjacentNodes;
}

int Distance(Node* node1, Node* node2)
{
    const int size = edges.size();
    for (int i = 0; i < size; ++i)
    {
        Edge* edge = edges.at(i);
        if (edge->Connects(node1, node2))
        {
            return edge->distance;
        }
    }
    return -1;
}

bool Contains(vector<Node*>& nodes, Node* node)
{
    const int size = nodes.size();
    for (int i = 0; i < size; ++i)
    {
        if (node == nodes.at(i))
        {
            return true;
        }
    }
    return false;
}

///////////////////

void PrintShortestRouteTo(Node* destination)
{
    Node* previous = destination;
    cout<< destination->distanceFromStart << endl;
    while (previous)
    {
        cout << previous->id << " ";
        previous = previous->previous;
    }
    cout << endl;
}

vector<Edge*>* AdjacentEdges(vector<Edge*>& Edges, Node* node);
void RemoveEdge(vector<Edge*>& Edges, Edge* edge);

vector<Edge*>* AdjacentEdges(vector<Edge*>& edges, Node* node)
{
    vector<Edge*>* adjacentEdges = new vector<Edge*>();

    const int size = edges.size();
    for (int i = 0; i < size; ++i)
    {
        Edge* edge = edges.at(i);
        if (edge->node1 == node)
        {
            cout << "adjacent: " << edge->node2->id << endl;
            adjacentEdges->push_back(edge);
        }
        else if (edge->node2 == node)
        {
            cout << "adjacent: " << edge->node1->id << endl;
            adjacentEdges->push_back(edge);
        }
    }
    return adjacentEdges;
}

void RemoveEdge(vector<Edge*>& edges, Edge* edge)
{
    vector<Edge*>::iterator it;
    for (it = edges.begin(); it < edges.end(); ++it)
    {
        if (*it == edge)
        {
            edges.erase(it);
            return;
        }
    }
}







