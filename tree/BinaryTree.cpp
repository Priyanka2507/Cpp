#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree
{
public:
    Node *insert(Node *root, int data)
    {
        if (root = NULL)
        {
            root = new Node(data);
            return root;
        }
        root->left = insert(root->left, data);
        root->right = insert(root->right, data);
        return root;
    }
    void display(Node *root)
    {
        if (root == NULL)
        {
            cout << "\nNULL";
            return;
        }
        cout << root->data << " , ";
        display(root->left);
        display(root->right);
        return;
    }
    Node *createTree()
    {
        int d;
        cin >> d;
        if (d == -1)
        {
            return NULL;
        }
        Node *root = new Node(d);
        root->left = createTree();
        root->right = createTree();
        return root;
    }
};

void levelorder(Node *root, vector<int> &v)
{
    queue<Node *> q;
    if (root == NULL)
        return;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->right != NULL)
            q.push(temp->right);
        if (temp->left != NULL)
            q.push(temp->left);
        v.push_back(temp->data);
    }
    reverse(v.begin(), v.end()); //O(n) time alternate : using stacks for reversing elements O(n) time and space
    return;
}
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> v;
    levelorder(root, v);
    return v;
}

// vector<int> levelOrder2(Node *node)
// {
//     queue<Node *> q;
//     vector<int> v;
//     q.push(node);
//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();
//         v.push_back(temp->data);

//         if (temp->left)
//         {
//             q.push(temp->left);
//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
//     return v;
// }

int main()
{
    Node *root = NULL;
    BinaryTree bt;
    //root = bt.createTree();
    bt.insert(root, 8);
    bt.display(root);
    return 0;
}