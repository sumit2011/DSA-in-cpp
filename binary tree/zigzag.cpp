// zigzag traversal or spiral traversal
//

// user function template
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> result;
        // base case
        if (root == NULL)
        {
            return result;
        }

        queue<Node *> q; // queue to store root node
        q.push(root);

        bool lefttoright = true; // flag to check moving from right to left or left to right

        while (!q.empty())
        {
            int size = q.size(); // check how many data is present in the queue

            vector<int> ans(size); // vector to store data from one level

            for (int i = 0; i < size; i++) // run for loop until we get
            {
                Node *frontnode = q.front(); // pop the front node from the queue
                q.pop();

                // int index = lefttoright ? i : size-i-1;
                int index;
                if (lefttoright)
                {
                    index = i; // if left to right then insert from starting in the vector
                }
                else
                    index = size - i - 1; // else insert from the last insdex

                ans[index] = frontnode->data;
                if (frontnode->left)
                {
                    q.push(frontnode->left); // if left is present then push to queue
                }

                if (frontnode->right)
                {
                    q.push(frontnode->right); // if right is present then push to queue
                }
            }

            lefttoright = !lefttoright; // change the direction
            for (auto i : ans)
            {
                result.push_back(i); // now push the data from the ans to result vector
            }
        }
        return result;
    }
};