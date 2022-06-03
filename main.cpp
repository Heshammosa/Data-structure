/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* left, * right;

	Node(int value)
	{
		data = value;
		left = right = NULL;
	}
};

class BST
{
public:
	Node* root;

	BST()
	{
		root = NULL;
	}

	Node* Insert(Node* r, int item)
	{
		if (r == NULL)
		{
			Node* newnode = new Node(item);
			r = newnode;
		}

		else if (item < r->data)
			r->left = Insert(r->left, item);
		else
			r->right = Insert(r->right, item);

		return r;
	}

	void Insert(int item)
	{
		root = Insert(root, item);
	}

	void Preorder(Node* r) // root ->left->right
	{
		if (r == NULL)
			return;
		cout << r->data << "\t";
		Preorder(r->left);
		Preorder(r->right);
	}

	void Inorder(Node* r) // left->root -> right
	{
		if (r == NULL)
			return;

		Inorder(r->left);
		cout << r->data << "\t";
		Inorder(r->right);

	}
	void Postorder(Node*r)// Left/right/ root
	{
		if (r == NULL)
			return;
		Postorder(r->left);
		Postorder(r->right);
		cout << r->data << "\t";
	

	 }

	Node* Search(Node* r, int ky) {
		if (r == NULL)
			return NULL;

		else if (r->data == ky)
			return r;

		else if (ky < r->data)
			return Search(r->left, ky);

		else
			return Search(r->right, ky);

	}
	bool Search(int ky) {
		Node* re = Search(root, ky);
		if (re == NULL)
			return false;
		else
			return true;


	}
	Node* Findmin(Node* r) {
		if (r == NULL)
			return NULL;
		else if (r->left == NULL)
			return r;
		else
			return Findmin(r->left);

	}
	Node* Findmax(Node* r) {
		if (r == NULL)
			return NULL;
		else if (r->right == NULL)
			return r;
		else
			return Findmax(r->right);


	}
};


int main() {
	BST btt;
	btt.Insert(25);

	btt.Insert(90);

	btt.Insert(15);

	btt.Insert(50);

	btt.Insert(12);

	btt.Insert(8);

	cout << "Display the Tree Contenet\n";

	btt.Preorder(btt.root);

	cout << " \n.............\n";

	btt.Inorder(btt.root);
	cout << " \n.............\n";
	 
	btt.Postorder(btt.root);

	int ky;
	cout << "Enter item to searh for\n";
	cin >> ky;
	if (btt.Search(ky))
		cout << "found";
	else
		cout << "not found";

	cout << " \n.............\n";
	
	cout << "Find Minimum \n";
	Node *min = btt.Findmin(btt.root);
	if (min == 0) 
		cout << "No Items Exist";
	else
		cout << "Minimum is  " << min->data << "\n";

	cout << "Find Maximum \n";
	Node* max = btt.Findmax(btt.root);
	if (max == 0)
		cout << "No Items Exist \n";
	else
		cout << "Maximum is  " << max->data << "\n";
	

}