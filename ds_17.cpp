#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node*left;
	node*right;

	int height;
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->height = 1;
	}
};
int height(node*root)
{
	if (root == NULL)
		return 0;
	else
		return root->height;
}
node *rotate_right(node *r)
{
	node *l = r->left;
	node *T2 = l->right;

	// Perform rotation
	l->right = r;
	r->left = T2;

	// Update heights
	r->height = max(height(r->left),
	                height(r->right)) + 1;
	l->height = max(height(l->left),
	                height(l->right)) + 1;

	// Return new root
	return l;
}
node *rotate_left(node *l)
{
	node *r = l->right;
	node *T2 = r->left;


	r->left = l;
	l->right = T2;


	l->height = max(height(l->left),
	                height(l->right)) + 1;
	r->height = max(height(r->left),
	                height(r->right)) + 1;


	return r;
}
node*insert_node(node*root, int data)
{
	if (root == NULL)
	{
		return new node(data);
	}
	if (data < (root->data))
	{
		root->left = insert_node(root->left, data);
	}
	else if (data > (root->data))
	{
		root->right = insert_node(root->right, data);
	}
	else
	{
		return root;
	}

	//calculate height
	root->height = 1 + max(height(root->left), height(root->right));

	int bf = height(root->left) - height(root->right);
	//rotations
	if (bf > 1 && data < (root->left->data))

		return rotate_right(root);

	if (bf < -1 && data > (root->right->data))
		return rotate_left(root);

	if (bf > 1 && data > root->left->data)
	{
		root->left = rotate_left(root->left);
		return rotate_right(root);
	}


	if (bf < -1 && data < root->right->data)
	{
		root->right = rotate_right(root->right);
		return rotate_left(root);
	}
	return root;
}
void preorder(node*root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	node*root = NULL;
	root = insert_node(root, 5);
	root = insert_node(root, 9);
	root = insert_node(root, 4);
	root = insert_node(root, 23);
	root = insert_node(root, 40);
	root = insert_node(root, 27);
	cout << "PREORDER TRAVERSAL OF FINAL AVL TREE" << endl;
	preorder(root);
}
