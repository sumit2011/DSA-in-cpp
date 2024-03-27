
// coding ninja

//recursive solution
bool searchInBST(BinaryTreeNode<int> *root, int x){
    if(root == NULL){
        return false;
    }

    if(root->data == x){
        return true;
    }
    if(root->data > x){
        return search(root->left, x);
    }
    else{
        return search(root->right, x);
    }
}

// itrative solution
bool searchInBST(BinaryTreeNode<int> *root, int x){
    
    BinaryTreeNode<int> * temp;
    while(temp != NULL){
        if(root->data == x){
            return true;
        }
        if(temp->data > x){
            temp = temp->left;
        }
        else{
            temp = temp->right
        }
    }
    return false;
}
