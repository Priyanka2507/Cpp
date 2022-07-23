#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *insert(node *root, int data)
{
    if (!root)
    {
        node *root = new node(data);
        return root;
    }
    root->left = insert(root->left, data);
    root->right = insert(root->right, data);
    return root;
}

void preOrder(node *root)
{
    if (root == NULL)
    {
        cout << "\nNULL";
        return;
    }
    cout << root->data << " , ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

node *createTree()
    {
        int d;
        cin >> d;
        if (d == -1)
        {
            return NULL;
        }
        node *root = new node(d);
        root->left = createTree();
        root->right = createTree();
        return root;
    }

int main()
{
    node *root = NULL;
    //root = insert(root, 4);
    root = createTree();
    preOrder(root);
    cout << endl;
    return 0;
}