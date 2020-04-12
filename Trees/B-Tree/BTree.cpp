#include <iostream>
#include "BTree.h"
using namespace std;

int nodes = 0;


BNode::BNode()
{
	nodeNumber = nodes++;
	numberOfKeys = 0;
	leaf = true;
	for (int i=0;i<4;i++)
		childs[i] = NULL;
	for (int i=0;i<3;i++)
		keys[i]=0;
}

void BNode::print()
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

void BNode::insertAfter(int key)
{
	int i = numberOfKeys;
	if (leaf)
	{
		while(i>0 && key<keys[i-1])
		{
			keys[i]=keys[i-1];
			i--;
		}
		keys[i]=key;
		numberOfKeys++;
	}
	else
	{
		while(i>0 && key<keys[i-1])
			i--;
		if(childs[i]!=NULL && childs[i]->numberOfKeys == 3)
		{
			splitChild(i);
			if (key>keys[i])
				i++;
		}
		childs[i]->insertAfter(key);
	}
}

void BNode::splitChild(int childNumber)
{
	BNode* child = childs[childNumber];
	BNode* newNode = new BNode();
	newNode->leaf = child->leaf;
	newNode->numberOfKeys = 1;
	newNode->keys[0] = child->keys[2];

	if(!child->leaf)
	{
		newNode->childs[0]=child->childs[2];
		newNode->childs[1]=child->childs[3];
	}

	child->numberOfKeys = 1;
	for(int j=numberOfKeys;j>childNumber;j--)
		childs[j+1]=childs[j];
	childs[childNumber+1] = newNode;
	for(int j=numberOfKeys-1;j>=childNumber;j--)
		keys[j+1]=keys[j];
	keys[childNumber]=child->keys[1];
	numberOfKeys++;
}

void BTree::insert(int key)
{
	if(root->numberOfKeys == 3)
	{
		BNode* newNode = new BNode();
		newNode->childs[0]=root;
		newNode->leaf = false;
		root = newNode;
		newNode->splitChild(0);
		newNode->insertAfter(key);
	}
	else
		root->insertAfter(key);
}

BTree::BTree()
{
	BNode* root = new BNode();
	this->root = root;
}

void BTree::print()
{
	root->print();
}

BNode* BTree::findNode(int key)
{
	BNode* node= this->root;
	while (node != NULL)
	{
		if (node->keys[0] == key || node->keys[node->numberOfKeys-1] == key)
			return node;
		if(key < node->keys[0])
			node = node->childs[0];
		else if(key > node->keys[node->numberOfKeys-1])
			node = node->childs[node->numberOfKeys];
		else for(int i=0; i<node->numberOfKeys-1; i++)
		{
			if (node->keys[i] == key)
				return node;
			if (node->keys[i] < key && key < node->keys[i+1])
			{
				node = node->childs[i+1];
				break;
			}
		}
	}
	return NULL;
}
