//diameter of a binary tree 
// longest path between any two end nodes (leaf/root)

//ques link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

//video link:

//approach:


class Solution{
    private:
    int height(struct Node* node){
        //base case
        if(node==NULL){
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        int ans = max(left,right)+1;
        return ans;
    }

    public:
    // function to return the diameter of a binary tree
    
    pair<int,int> diameterFast(Node* root){
        if(root == NULL) {
            pair<int,int> p = make_par(0,0);
            return p;
        }

        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int,int> ans;
        ans.first = max(op1 , max(op2,op3));
        ans.second = max(left.second,right.second)+1;
        
        return ans;
    }
    // time complexicity: O(n)

    int diameter(Node* root){
        return diameterFast(root).first;
    }

    int diameter(Node* root){
        if(root == NULL){
            return 0;
        }
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right) + 1;

        int ans = max(op1, max(op2, op3));
        return ans;
    }
    // time complexicity: O(n^2 )
};

