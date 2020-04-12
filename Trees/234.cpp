#include <iostream>
using namespace std;

int nodes = 0;

class Node
{
	public:
	int keys[3];
	Node* childs[4];
	int numberOfKeys;
	bool leaf;
	int nodeNumber;

	Node();
	void print();
	void insertAfter(int key);
	void splitChild(int childNumber);
};

Node::Node()
{
	nodeNumber = nodes++;
	numberOfKeys = 0;
	leaf = true;
	for (int i=0;i<4;i++)
		childs[i] = NULL;
	for (int i=0;i<3;i++)
		keys[i]=0;
}

void Node::print()
{
	if (leaf)
		cout<<"Leaf ";
	else
		cout<<"Middle node ";
	cout<<"["<<nodeNumber<<"] with "<<numberOfKeys<<" keys: ";
	for(int i=0;i<numberOfKeys;i++)
		cout<<keys[i]<<" ";
	cout<<"Childs ";
	for(int i=0;i<numberOfKeys+1;i++)
		if(childs[i]!=NULL)
			cout<<i<<":"<<childs[i]->nodeNumber<<" ";
	cout<<endl;

	for(int i=0;i<numberOfKeys+1;i++)
		if(childs[i]!=NULL)
			childs[i]->print();

}

void Node::insertAfter(int key)
{
	//To do
}

void Node::splitChild(int childNumber)
{
	//To do
}

class Tree
{
	public:
	Node* root;
	Tree();
	void print();
	void insert(int key);
};

void Tree::insert(int key)
{
	if(root->numberOfKeys == 3)
	{
		Node* newNode = new Node();
		newNode->childs[0]=root;
		newNode->leaf = false;
		root = newNode;
		newNode->splitChild(0);
		newNode->insertAfter(key);
	}
	else
		root->insertAfter(key);
}

Tree::Tree()
{
	Node* root = new Node();
	this->root = root;
}

void Tree::print()
{
	root->print();
}

int main()
{
	Tree* tree = new Tree();

	int key = -1;
	for(;;)
	{
		cout<<"New key: ";
		cin>>key;
		if(key==-1)
			break;
		tree->insert(key);
		tree->print();
	}


}
