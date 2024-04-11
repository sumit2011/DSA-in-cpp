// eventual safe states

// gfg : https://www.geeksforgeeks.org/problems/eventual-safe-states/1


class Solution {
  public:
  
    bool dfs(int vis[], int pathvis[] , vector<int> adj[] , int node , int check[]){
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(vis, pathvis , adj , it , check)){
                    
                    check[node] = 0;
                    return true;
                }
            }
            
            else if(pathvis[it]){
                check[node] = 0;
                return true;
            }
        }
        
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        int vis[V] = {0};
        int pathvis[V] = {0};
        int check[V] = {0};
        vector<int> ans;
        
        
        for(int i =0 ; i<V ; i++){
            if(!vis[i]){
                dfs(vis , pathvis , adj , i , check);
            }
        }
        
        for(int i=0; i<V; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
