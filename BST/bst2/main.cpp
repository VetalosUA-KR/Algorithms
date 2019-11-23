#include <iostream>

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

/*void Add(Node*& root, int k, Node * par)
{
	if (root == NULL)
	{
		root = new Node;
		root->key = k;
		root->left = NULL;
		root->right = NULL;
		root->parent = par;
	}
	else
	{
		if (root->key > k) Add(root->left, k, root);
		else Add(root->right, k, root);
	}
}*/

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
    if(r->left == nullptr && r->right == nullptr)
    {
        if(r->parent->left = r) r->parent->left = nullptr;
        if(r->parent->right = r) r->parent->right = nullptr;
        delete r;
        return;
    }
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
    /*else
    {
        Node * nas =
    }*/
}

void wypisz(Node * current, int l)
{
     if(current != nullptr)
     {
         wypisz(current->right, l+3);
         for(int i = 1; i <= l; i++)
         {
             cout<<"   ";
         }
         cout<<current->key<<endl;
         wypisz(current->left, l+3);
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
	Node* root = NULL;
	int tab[9] = { 8,4,9,10,3,5,6,2,7};
	for (int i = 0; i < 9; i++)
	{
		Add(root, tab[i], nullptr);
	}
	printInOrder(root);
    cout<<endl<<"to sekwencijnie"<<endl;
    Node * tmp = minElement(root);
    while(tmp)
    {
        cout<<tmp->key;
        tmp = nastepnik(tmp);
        if(tmp!= nullptr) cout<<" -- ";
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    wypisz(root, 0);
    cout<<endl<<"*********************************************"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    Node * el = serchElement(root, 3);

    deleteElement(el);
    wypisz(root, 0);


	return 0;
}







