
class Solution {
  public:
  
  // dfs function
    
    void dfs(int node, vector<int> adj[], int vis[] ){
        
        vis[node] = 1;        // mark node visited
       
        // traverse all its neighbours of the node
        for(auto i: adj[node]){
            // if non visited call dfs again 
            if(!vis[i]){
                // recursive call 
                dfs(i, adj , vis );
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        // conversion from adjacency matrix to adjancency list
        vector<int> adjList[V];
        for(int i =0; i<V ; i++){
            for(int j=0 ; j< V ;j++){
                if(adj[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        int vis[V] = {0};
        int count = 0;
        for(int i = 0; i< V; i++){
            if(!vis[i]){
                count++;
                dfs(i,adjList,vis);
            }
        }
        
        return count;
        
    }

};