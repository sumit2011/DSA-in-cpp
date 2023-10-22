//zigzag traversal or spiral traversal
//



class Solution{
    public:
    vector<int> zigzagtraversal(Node* root){
        vector<int> result;
        if(root == NULL){
            return result:
        }
        queue<Node*> q;
        q.push(root);

        bool lefttoright = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size);

            // level process

            for (int i = 0; i < size; i++)
            {
                Node* frontnode = q.front();
                q.pop();

                //normal insert or reverse insert

                int index = lefttoright ? i: size - i -1;
                ans[index] = frontnode->data;

                if(frontnode->left)
                q.push(frontnode->left);

                if(frontnode->right)
                q.push(frontnode->right);
            }

            //direction change
            lefttoright= !lefttoright;

            for( auto i: ans){
                result.push_back(i);
            }
        }  
        return result;
    }
};