// detect cycle in directed graph

// gfg: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

bool dfs(vector<int> adj[] , int vis[] , int pathvis[] , int node){
        vis[node] = 1;
        pathvis[node] = 1;
        
        // traverse the adjacent ndoes
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(adj , vis , pathvis , it)){
                    return true;
                }
            }
            
            // if the node has been previously visited
            // but it has to be visited on the same path
            
            else if(pathvis[it]){
                return true;
            }
        }
        
        pathvis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]= {0};
        int pathvis[V] = {0};
        
        for(int i =0; i< V; i++){
            if(!vis[i]){
                if(dfs(adj , vis , pathvis , i)){
                    return true;
                }
            }
        }
        return false;
    }