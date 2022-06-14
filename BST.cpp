#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
	public:
		int value;
		TreeNode *right;
		TreeNode *left;
	TreeNode(int val)
	{
		value=val;
		right=left=NULL;
	}
};
class BST{
	public:
	TreeNode *root;
	BST()
	{
		root=NULL;
	}
  	void addval(int val)
	{
		if(root==NULL){
			root=new TreeNode(val);
			cout<<root->value<<" \n";
		}
		else
		{
			TreeNode *temp=root;
			TreeNode *n=new TreeNode(val);
			while(temp!=NULL)
			{
				if(temp->value < n->value && temp->right==NULL)
				{
					temp->right=n;
					cout<<temp->right->value<<" \n";
					break;
				}
				else if(temp->value < n->value)
				{
					temp=temp->right;
				}
				else if(temp->value > n->value && temp->left==NULL)
				{
					temp->left=n;
					cout<<temp->left->value<<" \n";
					break;
				}
				else if(temp->value > n->value)
				{
					temp=temp->left;
				}
			 }
		}
	}
	void Preorder(TreeNode * temp) 
  {
    if (temp == NULL)
      return;
    cout << temp -> value << " ";
    Preorder(temp -> left);
    Preorder(temp -> right);
  }


};



int main()
{
	BST b1;
	b1.addval(5);
	b1.addval(10);
	b1.addval(3);
	b1.addval(51);
	b1.addval(110);
	b1.addval(13);
	cout<<"\nPreOrder Traversal\n";
	b1.Preorder(b1.root);
	cout<<endl;

	

				
	
}
