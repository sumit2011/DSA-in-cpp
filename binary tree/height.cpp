//height or depth of binary tree
//longest path between root node and leaf node

//approach: recursion    

//ques link: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

//video link: https://www.youtube.com/watch?v=nHMQ33LZ6oA&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=69

#include<iostream>


class Solution{
    public:
//function to find the height of a binary tree
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
     
};


//time complexicity: O(n)

//space complexicity: O(height)