#ifndef BTREE_H
#define BTREE_H

class BNode
{
	public:
	int keys[3];
	BNode* childs[4];
	int numberOfKeys;
	bool leaf;
	int nodeNumber;

	BNode();
	void print();
	void insertAfter(int key);
	void splitChild(int childNumber);
};

class BTree
{
	public:
	BNode* root;
	BTree();
	void print();
	void insert(int key);
	BNode* findNode(int key);
};

#endif
