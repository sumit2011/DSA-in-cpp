

// to check given binary tree is a bst or not

bool isBSTUtil(Node* root, int min, int max) {
        // Base case: An empty tree is a BST
        if (root == NULL) {
            return true;
        }

        // If this node violates the min/max constraint, then it's not a BST
        if (root->data <= min || root->data >= max) {
            return false;
        }

        // Otherwise, check the subtrees recursively
        // tightening the min or max constraint
        return isBSTUtil(root->left, min, root->data) &&
               isBSTUtil(root->right, root->data, max);
    }

    bool isBST(Node* root) {
        // Initialize min and max values
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }