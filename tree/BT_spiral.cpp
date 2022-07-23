#include <iostream>
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

void printKthLevelOdd(Node *root, int k)
{
    if (root == NULL)
    {
        cout << "\n Empty tree";
        return;
    }

    if (k == 0)
    {
        cout << root->data << " , ";
        return;
    }
    printKthLevelOdd(root->right, k - 1);
    printKthLevelOdd(root->left, k - 1);
}

void printKthLevelEven(Node *root, int k)
{
    if (root == NULL)
    {
        cout << "\n Empty tree";
        return;
    }

    if (k == 0)
    {
        cout << root->data << " , ";
        return;
    }
    printKthLevelEven(root->left, k - 1);
    printKthLevelEven(root->right, k - 1);
}

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
void printspiral(Node *root)
{
    int n = height(root, 0);
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            printKthLevelEven(root, i);
        }
        if (i % 2 == 0)
        {
            printKthLevelOdd(root, i);
        }
        cout << endl;
    }
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

int main()
{
    Node *root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('c');
    root->left->left = new Node('d');
    root->left->right = new Node('e');
    root->right->left = new Node('f');
    root->right->right = new Node('g');
    root->left->left->left = new Node('h');
    root->left->left->right = new Node('i');
    root->left->right->left = new Node('j');
    root->left->right->right = new Node('k');
    root->right->left->left = new Node('l');
    root->right->left->right = new Node('m');
    root->right->right->left = new Node('n');
    root->right->right->right = new Node('o');

    inOrder(root);
    cout << endl;
    cout << "height : " << height(root, 0) + 1 << endl;
    printspiral(root);
}