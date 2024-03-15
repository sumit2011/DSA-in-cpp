#include<iostream>
#include <queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data=d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {
    cout<<"Enter The Data:" <<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data== -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of "<<data << endl;
    root->left = buildTree(root->left);
    cout <<" Enter data for inserting in right of "<<data<< endl;
    root -> right = buildTree(root->right);
    return root;

}

//level order triversal
void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<< temp -> data << " ";
            if(temp-> left) {
            q.push ( temp-> left);
        }

        if(temp->right){
            q.push ( temp-> right);
        }
        }
        

    }
}

//inorder traverdal
void inorder(node* root)
{
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//preorder traversal
void preorder(node* root)
{
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//post traversal
void postorder(node* root)
{
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}



void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"enter data for root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<< " enter left node for: "<<root->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout<< "enter right node for: "<<root->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main() {

    node* root = NULL;

    // buildFromLevelOrder(root);
    // levelOrderTraversal(root);

//input data set:  1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    root = buildTree(root);
    cout<<"the given tree is:"<<endl; 
    
//input data set:  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);


    cout<<"inorder traversal is: ";
    inorder(root);
    cout<<endl;

    cout<<"preorder traversal is: ";
    preorder(root);
    cout<<endl;

    cout<<"postorder traversa is: ";
    postorder(root);
    return 0;

}