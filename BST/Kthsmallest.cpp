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
int solve(Node *root, int k, int &count)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = solve(root->left, k, count);
    if(left != -1){
        return left;
    }
    cout<<root->data << endl;
    count++;
    if (count == k)
    {
        // cout << k << "th smallest no is: " << root->data << endl;
        return root->data;
    }
    return solve(root->right, k, count);
}
// output->
    // enter data to create bst 
    // 50 20 70 10 30 90 110 -1

    // 10
    // 20
    // 30
    // kth smallest no is: 30


// function to find kth smallest
// void solve(Node *root, int k, int &count)
// {
//     if (root == NULL)
//     {
//         return ;
//     }
//     solve(root->left, k, count);
//     cout<<root->data << endl;
//     count++;
//     if (count == k)
//     {
//         cout << k << "th smallest no is: " << root->data << endl;
//     }
//     solve(root->right, k, count);
// }

// output->
    // enter data to create bst 
    // 50 20 70 10 30 90 110 -1

    // 10
    // 20
    // 30
    // 3th smallest no is: 30
    // 50
    // 70
    // 90
    // 110

int main()
{
    Node *root = NULL;
    cout << "enter data to create bst " << endl;
    takeinput(root);
    cout << endl;
    int count = 0;
    int ans = solve(root, 3, count);
    cout << "kth smallest no is: " << ans <<endl;

    return 0;
}
// input-> 50 20 70 10 30 90 110 -1
// inorder -> 10 20 30 50 70 90 110
