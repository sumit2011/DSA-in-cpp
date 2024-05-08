// minimum distnce between two given nodes in a given binary tree

// to find the distance
    int dist (Node* root , int num){
        if(root == NULL){
            return 0;
        }
        if(root ->data == num){
            return 1;
        }
        int left = dist(root->left , num);
        int right = dist(root->right , num);
        if(left){
            int ans = left + 1;
            return ans;
        }
        if(right){
            int ans = right + 1;
            return ans;
        }
    }
    

// to find lowest common ancestor    
    Node* lca(Node* root , int a , int b){
        if(root == NULL){
            return NULL;
        }
        if( root->data == a || root->data == b){
            return root;
        }
        
        Node* left= lca(root->left , a, b);
        Node* right = lca(root->right , a , b);
        
        if(left != NULL && right != NULL){
            return root;
        }
        
        if(left == NULL && right!= NULL){
            return right;
        }
        
        if(left != NULL && right == NULL){
            return left;
        }
        else{
            return NULL;
        }
    }
    
    

    int findDist(Node* root, int a, int b) {
        // Your code here
        pair<int , int> p;
        Node* lcanode = lca(root ,a, b);
        // cout<<lcanode->data<<endl;
        
        int dist1 = dist(lcanode , a);
        int dist2 = dist(lcanode , b);
        int ans = dist1 + dist2 - 2;
        return ans;
        
    }