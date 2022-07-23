#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class linkedList
{
public:
    Node *insertAtbeg(int d, Node *&head)
    {
        if (head == NULL)
        {
            head = new Node(d);
            return head;
        }
        Node *temp = new Node(d);
        temp->next = head->next;
        head = temp;
        return head;
    }

    Node *insertAtEnd(int d, Node *&head)
    {
        if (head == NULL)
        {
            head = new Node(d);
            return head;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *temp2 = new Node(d);
        temp->next = temp2;
        return head;
    }

    Node *insertInMid(int d, Node *&head, int p)
    {
        if (head == NULL)
        {
            head = new Node(d);
            return head;
        }
        Node *temp = new Node(d);
        Node *temp2 = head;
        while (--p)
        {
            temp2 = temp2->next;
        }
        temp = temp2->next;
        temp2->next = temp;
        return head;
    }

    void deleteAtEnd(Node *head)
    {
        if (head == NULL)
        {
            cout << "\nEmpty list";
            return;
        }
        while (head->next != NULL)
        {
            head = head->next;
        }
        delete head;
    }

    Node *deleteAtBeg(Node *&head)
    {
        if (head == NULL)
        {
            cout << "\nEmpty list";
            return head;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    bool search(int key, Node *head)
    {
        if (head == NULL)
        {
            cout << "\nEmpty list";
            return False;
        }
        while (head->next != NULL)
        {
            if (head->data == key)
            {
                return true;
            }
            head = head->next;
        }
        return false;
    }

    void display(Node *head)
    {
        while (head->next != NULL)
        {
            cout << head->data << " --> " << endl;
            head = head->next;
        }
    }

    Node *reverseList(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *p = NULL;
        Node *c = head;
        Node *n = NULL;
        while (c != NULL)
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }

    Node *find_mid(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }
        Node *fast = head;
        Node *slow = head;
        while (fast->next != NULL && fast != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    /*void k_reverse(Node *head, int k) //
    {
        Node *temp = head;
        int len = 0;
        while (temp->next != NULL)
        {
            temp = temp->next;
            len++;
        }

        for (int i = 0; i < (len / k); i++)
        {
        }
    }*/

    void deleteNode(Node *node)  //delete node w/o head
    {
        while (node->next->next != NULL)
        {
            node->data = node->next->data;
            node = node->next;
        }
        Node *temp = node->next;
        node->data = node->next->data;
        node->next = NULL;
        node = temp->next;
        delete node;
    }

    int intersectPoint(Node *head1, Node *head2) //Y ll
    {
        // Your Code Here
        int m, n = 0;
        Node *temp1 = head1;
        Node *temp2 = head2;

        if (head1 == NULL || head2 == NULL)
        {
            return -1;
        }

        while (temp1->next != NULL)
        { //length of ll1
            temp1 = temp1->next;
            m++;
        }

        while (temp2->next != NULL)
        { //length of ll2
            temp2 = temp2->next;
            n++;
        }

        temp2 = head2;
        temp1 = head1;
        int diff = abs(m - n);

        if (m > n)
        {
            while (--diff)
            {
                temp1 = temp1->next;
            }

            while (temp1->data != temp2->data || temp1 == NULL)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            if (temp1 == NULL)
                return -1;
            else
                return temp1->data;
        }
        else if (n > m)
        {
            while (--diff)
            {
                temp2 = temp2->next;
            }

            while (temp1->data != temp2->data || temp2 == NULL)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            if (temp2 == NULL)
                return -1;
            else
                return temp2->data;
        }
    }

    bool isPalindrome(Node *head)
    {
        //Your code here
        if (head == NULL)
        {
            return 0;
        }
        if (head->next == NULL)
        {
            return 1;
        }

        int flag = 1;
        Node *temp = find_mid(head);
        temp = reverseList(temp);
        while (temp != NULL)
        {
            if (head->data != temp->data)
            {
                flag = 0;
                break;
            }
            head = head->next;
            temp = temp->next;
        }

        return flag;
    }
};
