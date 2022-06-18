#include <iostream>
using namespace std;


struct Node {
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


void printPreorder(struct Node* node)
{
	if (node == NULL)
		return;

	cout << node->data << " ";

	printPreorder(node->left);

	printPreorder(node->right);
}

int main()
{
	struct Node* root = newNode(100);
	root->left = newNode(200);
	root->right = newNode(300);
	root->left->left = newNode(400);
	root->left->right = newNode(500);

	printPreorder(root);



	return 0;
}

