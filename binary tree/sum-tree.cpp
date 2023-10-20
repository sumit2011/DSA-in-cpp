// sum of the binary tree

//ques link: https://practice.geeksforgeeks.org/problems/sum-tree/1


class Solution{
    public:

    pair<bool,int> isSumTreeFast(Node* root){
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }

        if(root->left == NULL && root->right == NULL){
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);

        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;

        bool condn = root->data == leftAns.second + rightAns.second;

        pair<bool,int> ans;

        if(isLeftSumTree && isRightSumTree && condn){
            ans.first = true;
            ans.second = 2*root->data;
        }
        else{
            ans.first = false;
        }
        return ans;

    }
    bool isSumTree(Node* root){
        return isSumTreeFast(root).first;
    }
}