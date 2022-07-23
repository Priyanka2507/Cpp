#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node(char data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

int height(Node *root, int cnt)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return cnt;
    int h1 = height(root->left, cnt + 1);
    int h2 = height(root->right, cnt + 1);
    return max(h1, h2) + 1;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void levelOrder(Node *node)
{
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << (temp->data) << " , ";

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    return;
}

void leftView(Node *root, int level, int &max_level)
{
    if (root == NULL)
    {
        return;
    }
    if (max_level < level)
    {
        cout << root->data << endl;
        max_level = level;
    }

    leftView(root->left, level + 1, max_level);
    leftView(root->right, level + 1, max_level);
}

void printLeftView(Node *root)
{
    int max_level = 0;
    leftView(root, 1, max_level);
    return;
}

int main()
{
    Node *root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('c');
    root->left->left = new Node('d');
    root->left->right = new Node('e');
    root->right->left = new Node('f');
    root->right->right = new Node('g');
    root->left->right->left = new Node('j');
    root->left->right->right = new Node('k');
    root->right->left->left = new Node('l');
    root->right->left->right = new Node('m');
    root->right->right->left = new Node('n');
    root->right->right->right = new Node('o');

    levelOrder(root);
    cout << endl;
    cout << "height : " << height(root, 0) + 1 << endl;
    cout << "Left View : \n";
    printLeftView(root);
    return 0;
}