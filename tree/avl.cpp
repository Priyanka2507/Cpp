#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int d;
    node *right;
    node *left;
    node(int val)
    {
        d = val;
        right = NULL;
        left = NULL;
    }
};

int height(node *root)
{
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}

int bal(node *root)
{
    if (root == NULL)
        return 0;
    return (height(root->left) - height(root->right));
}

node *leftRotate(node *root)
{
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

node *rightRotate(node *root)
{
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

node *insert(node *root, int d)
{
    if (root == NULL)
    {
        node *temp = new node(d);
        return temp;
    }
    if (d > root->d)
    {
        root->right = insert(root->right, d);
    }
    else if (root->d > d)
    {
        root->left = insert(root->left, d);
    }

    //left left case
    if (bal(root) > 1 && d < root->left->d)
    {
        return rightRotate(root);
    }
    //left right case
    if (bal(root) > 1 && d > root->left->d)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //right right case
    if (bal(root) < -1 && d > root->right->d)
    {
        return leftRotate(root);
    }
    //right left case
    if (bal(root) < -1 && d < root->right->d)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void display(node *root)
{
    if (root == NULL)
        return;
    cout << root->d << " , ";
    display(root->left);
    display(root->right);
}

int main()
{
    // int n, a;
    // cin >> n;
    // vector<int> arr;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a;
    //     arr.push_back(a);
    // }

    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    display(root);

    return 0;
}