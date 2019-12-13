#include <iostream>

using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;

	void Add(Node * &root,int k);

	void printInOrder(Node* root);
};

void Add (Node * &root,int k)
{
	    if (root == NULL)
        {

            root = new Node;
            root->key = k;
            root->left = NULL;
            root->right = NULL;
        }
        else
        {
            if (root->key > k) Add(root->left, k);
            else Add(root->right, k);
        }
	}

void printInOrder(Node* root)
{
	if (!root) return;
	printInOrder(root->left);
	cout << root->key << " ";
	printInOrder(root->right);
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


int main()
{
	Node* root = NULL;
	int tab[] = { 8,4,9,10,3,4,6,2,7};
	for (int i = 0; i < 9; i++)
	{
		Add(root, tab[i], nullptr);
	}
	printInOrder(root);
    cout<<endl<<"to sekwencijnie"<<endl;
    Node * tmp = minElement(root);
    while(tmp)
    {
        cout<<tmp->key<<" -- ";
        tmp = nastepnik(tmp);
    }


	/*Add(root, 9, nullptr);
	Add(root, 9, nullptr);*/

	return 0;
}












