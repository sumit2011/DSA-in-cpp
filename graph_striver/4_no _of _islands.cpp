// no of islands
// gfg: 

// Function to find the number of islands.
    
    // void bfs(int row , int col, vector<vector<int>> &vis , vector<vector<char>> &grid){
    //     vis[row][col] = 1;
    //     queue<pair<int,int>> q;
    //     q.push({row,col});
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     q.pop();
    //     while(!q.empty()){
    //         int row = q.front().first;
    //         int col = q.front().second;
    //         q.pop();
            
    //         for(int delrow = -1 ; delrow <=1 ; delrow++){
    //             for(int delcol = -1; delcol <= 1; delcol++){
    //                 int nrow= row+delrow;
    //                 int ncol = col + delcol;
    //                 if(nrow >=0 && nrow < n && ncol >=0 && ncol < m
    //                 && grid[nrow][ncol] == '1' && !vis[nrow][ncol] ){
    //                     vis[nrow][ncol] = 1;
    //                     q.push({nrow , ncol});
    //                 }
    //             }
    //         }
            
    //     }
        
    // }
    
    
    
    void dfs(int i,int j,vector<vector<char>> &grid){
        if(i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0' || i<0 || j<0){
        return;
        }
        grid[i][j]='0';
        dfs(i,j-1,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i+1,j,grid);
        dfs(i-1,j-1,grid);
        dfs(i-1,j+1,grid);
        dfs(i+1,j-1,grid);
        dfs(i+1,j+1,grid);
        
    }

 
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> vis(n , vector<int>(m,0));
        int cnt = 0;
        for(int row= 0 ; row< n;row++){
            for(int col =0; col<m; col++){
                if( grid[row][col] == '1') {
                    cnt++;
                    dfs(row,col, grid);
                }
            }
        }
        return cnt;
    }
