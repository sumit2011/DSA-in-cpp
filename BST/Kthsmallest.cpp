// kth smallest number in BST

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// insertion in BST
Node *insertIntoBst(Node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertIntoBst(root->right, d);
    }
    else
    {
        root->left = insertIntoBst(root->left, d);
    }
    return root;
}

// taking input
void takeinput(Node *&root)
{

    int data;
    cin >> data;
    while (data != -1)
    {
        insertIntoBst(root, data);
        cin >> data;
    }
}

// function to find kth smallest
void solve(Node *root, int k, int &count)
{
    if (root == NULL)
    {
        return - 1;
    }
    solve(root->left, k, count);
    count++;
    if (count == k)
    {
        cout << k << "th smallest no is: " << root->data;
    }
    solve(root->right, k, count);
}

int main()
{
    Node *root = NULL;
    cout << "enter data to create bst " << endl;
    takeinput(root);
    cout << endl;
    int count = 0;
    solve(root, 6, count);

    return 0;
}
// input-> 50 20 70 10 30 90 110 -1
// inorder -> 10 20 30 50 70 90 110
