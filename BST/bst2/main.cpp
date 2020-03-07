#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;
	Node* parent;

//	void Add(Node * &root,int k);
//	void printInOrder(Node* root);
};


Node * Add(Node*& r, int k, Node * par)
{
	if (r == NULL)
	{

		r = new Node;
		r->key = k;
		r->left = NULL;
		r->right = NULL;
		r->parent = par;
		return r;
	}
	else
	{
		if (r->key > k) return Add(r->left, k, r);
		else return Add(r->right, k, r);
	}
}


void printInOrder(Node* root)
{
	if (!root) return;
	printInOrder(root->left);
	cout << root->key << " ";
	printInOrder(root->right);
}



Node * minElement(Node * r)
{
    Node * tmp = r;
    if(tmp == nullptr) return nullptr;
    while(tmp->left != nullptr)
    {
        tmp = tmp->left;
    }
    return tmp;
}

Node * nastepnik(Node * r)
{
    Node * tmp = r;
    if(!r) return nullptr;
    if(r->right)
    {
        return minElement(r->right);
    }
    while(tmp->parent && (tmp == tmp->parent->right))
    {
        tmp = tmp->parent;
    }
    return tmp->parent;
}

int suma(Node* root)
{
	if (!root) return 0;
	return suma(root->left) + root->key + suma(root->right);
}

int wysokosc(Node * root)
{
	if (root==NULL) return 0;
	int L = wysokosc(root->left);
	int P = wysokosc(root->right);
	if (L > P) return L+1;
	else return P+1;
}

void deleteElement(Node *& r)
{
    if(!r) return;
    /// if deleted node has no children
    if(r->left == nullptr && r->right == nullptr)
    {
        if(r->parent->left = r) r->parent->left = nullptr;
        if(r->parent->right = r) r->parent->right = nullptr;
        delete r;
        return;
    }
    /// if deleted node have one children
    if(!r->left || !r->right)
    {
        Node * theOnlyChild = r->left;
        if(!theOnlyChild) theOnlyChild = r->right;
        theOnlyChild->parent = r->parent;
        if(r->parent->left == r) r->parent->left = theOnlyChild;
        else r->parent->right = theOnlyChild;
        delete r;
        return;
    }
    /// if deleted node have 2 children
    else
    {
        Node * nast = nastepnik(r);

        if(nast->parent->left == nast)nast->parent->left = nast->right;
        else nast->parent->right = nast->right;
        if(nast->right) nast->right->parent = nast->parent;

        nast->left = r->left;
        nast->right = r->right;
        nast->parent = r->parent;
        if(r->parent->left == r) r->parent->left = nast;
        else r->parent->right = nast;

        delete r;
        return;

    }
}

void rightRotation(Node * r)
{
    if(!r) return;
    if(!r->left) return;
    Node * LC = r->left;
    Node * RC = r->left->right;

    LC->parent = r->parent;
    if(r->parent)
    {
        if(r->parent->left == r) r->parent->left = LC;
        else r->parent->right = LC;
    }
    LC->right = r;
    r->parent = LC;
    r->left = RC;
    if(RC) RC->parent = r;
}

void leftRotation(Node * r)
{
    if(!r) return;
    if(!r->right) return;
    Node * LC = r->right;
    Node * RC = r->right->left;

    LC->parent = r->parent;
    if(r->parent)
    {
        if(r->parent->right == r) r->parent->right = LC;
        else r->parent->left = LC;
    }
    LC->left = r;
    r->parent = LC;
    r->right = RC;
    if(RC) RC->parent = r;
}

void dsw(Node *& root)
{
    if(abs(wysokosc(root->left) - wysokosc(root->right)) <= 1) return;

    Node * FakeRoot = new Node ();
    FakeRoot->right = root;
    Node * tmp = FakeRoot;
    root->parent = FakeRoot;
    while(tmp->right)
    {
        while(tmp->right->left)
        {
            rightRotation(tmp->right);
        }
        tmp = tmp->right;
    }

    tmp = FakeRoot;
    Node * tmp2 = FakeRoot;

    while(abs(wysokosc(tmp->left) - wysokosc(tmp->right)) > 1)
    {
        tmp = tmp2;
        while(tmp)
        {
            leftRotation(tmp->right);
            tmp = tmp->right;
        }
        tmp = tmp2->right;
    }
    root = FakeRoot->right;
}

void wypisz(Node * current, int l)
{
     if(current != nullptr)
     {
         wypisz(current->right, l+2);
         for(int i = 1; i <= l; i++)
         {
             cout<<"  ";
         }
         cout<<current->key<<endl;
         wypisz(current->left, l+2);
     }
}

Node * serchElement(Node * r,int numb)
{
    Node * tmp = r;
    if(!r) return nullptr;
    if(tmp->key == numb)return tmp;
    else
    {
        if(tmp->key > numb) serchElement(tmp->left, numb);
        else serchElement(tmp->right, numb); /// если заменить на if то не работает
    }
}



int main()
{
    srand(time(0));

	Node* root = NULL;

	ofstream out;          // поток для записи

    out.open("0-1.txt"); // окрываем файл для записи

    out << "0 - MAX" <<endl;


    for(int j = 100; j <= 10000; j += 100)
    {
        for (int i = 0; i <= j; i++)
        {
            Add(root, rand()%2, nullptr);
        }
        out<<j<<" "<<wysokosc(root)<<endl;
        root = nullptr;
    }




	/**Add(root, 10, nullptr);
	Add(root, 8, nullptr);
	Add(root, 15, nullptr);
	Add(root, 5, nullptr);
	Add(root, 9, nullptr);
	Add(root, 11, nullptr);
	Add(root, 13, nullptr);
	Add(root, 12, nullptr);*/

	//wypisz(root, 1);


	return 0;
}







