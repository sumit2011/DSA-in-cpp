#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data= d;
        this->left = NULL;
        this->right = NULL;
    }
};


// insertion in BST
// tc O(logn)
Node* insertIntoBst(Node* &root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        root->right = insertIntoBst(root->right, d);
    }
    else{
        root->left = insertIntoBst(root->left,d);
    }
    return root;
     

}

void takeinput(Node* &root){

    int data;
    cin>>data;
    while(data != -1){
        insertIntoBst(root,data);
        cin>>data;
    }
}

//level order triversal
void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        
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

// min value
Node* minval(Node* root){
    Node* temp = root;
    while(temp -> left != NULL){
        temp = temp->left;
    }
    return temp;
}

//maxval
Node* maxval(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

// delete a node in Bst
Node* deleteFromBST(Node* root, int val)
{
    // base case
    if(root == NULL){
        return root;
    }
    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp; 
        }
        // right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minval(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right , mini);
            return root;
        }
    }
    else if(root->data >val){
        root->left = deleteFromBST(root->left , val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right , val);
        return root;
    }
    
}

// kth smallest
void solve(Node* root, int k, int &count){
        if(root == NULL){
            return;
        }
        solve(root->left, k , count);
        count++;
        if(count == k){
            cout<< root->data;
        
        }
        solve(root->right, k ,count);
    }


int main(){
    Node* root = NULL;
    cout<<"enter data to create bst "<< endl;
    takeinput(root);
    cout<< "printing bst"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    int count = 0;
    solve(root,4 , count);

//     cout<<"minvalue: "<<minval(root)->data<<endl;
//     cout<<"maxvalue: "<<maxval(root)->data<<endl;
// // deletion
//     root = deleteFromBST(root,30);

//     cout<< "printing bst"<<endl;
//     levelOrderTraversal(root);

//     cout<<"minvalue: "<<minval(root)->data<<endl;
//     cout<<"maxvalue: "<<maxval(root)->data<<endl;

    return 0;
}
//50 20 70 10 30 90 110 -1
// inorder -> 10 20 30 50 70 90 110 

// Hw inorder predecessor
//    inorder succesor