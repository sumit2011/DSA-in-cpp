// merge two bst 
// coding ninja ques

// T.C = O(m+n)
// inorder of bst or to convert bst into sorted array

void inorder(Node* root, vector<int> &in){
    if(root == NULL)
        return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

}

vector<int> mergeArray(vector<int> &a, vector<int> b){
    vector<int> ans(a.size() + b.size())
    int i = 0, j=0;
    int k =0;

    while( i < a.size() && j < b.size())
    {
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
            an[k++] = b[j];
            j++;
        }
    }

    while(i < a.size()){
        ans[k++] = a[i];
        i++;
    }

    while(j< b.size()){
        ans[k++] = b[j];
        j++;
    }
    return ans;
}

Node* inorderToBst(int s, int e, vector<int> &in){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root->left = inorderToBst(s,mid -1, in);
    root->right = inorderToBst(mid+1, e, in);
    return root;
}


Node* mergebst( Node* root1, Node* root2 ){
    // step1: store inorder
    vector<int> bst1,bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // step2: merge both sorted arrays
    vector<int> mergearray = mergeArray(bst1,bst2);

    // step3: use merged array to build BST
    int s= 0, int e= mergearray.size() - 1;
    Node* ans = inorderToBst(s,e, mergearray);


    return ans;
}



// S.C = O(h1+h2)

