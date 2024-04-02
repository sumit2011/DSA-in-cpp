
// codingninja largest bst subtree


class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};


info solve(Node* root, int &ans){

    if(root == NULL){
        return {INT_MIN,INT_MAX, true, o};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right , ans);

    info currNode;

    currNode.size = left.size + right.size +1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    // answer update
    if(currNode.isBST){
        ans = max(ans , currNode.size);
    }
    return currNode;

}


int largestBST(Node* root){
    int maxsize = 0;
    info temp = solve(root , maxsize);
    return maxsize;
}