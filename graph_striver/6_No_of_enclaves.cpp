
// no of enclaves 
// gfg: https://www.geeksforgeeks.org/problems/number-of-enclaves/1

 void dfs(int row,int col ,vector<vector<int>> &vis, vector<vector<int>> &mat){
        
        vis[row][col] = 1;
        mat[row][col] = 0;
        // check for 
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0 ; i<4 ; i++){
            
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 1){
                
                dfs(nrow,ncol,vis,mat);
            }
        }

    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        // code here
        // n-> rows;
        // m-> col
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> mat = grid;
        for(int j =0; j < m; j++){
            
            // first row
            if(mat[0][j]== 1 && vis[0][j]== 0){
                //call dfs
                dfs(0,j,vis,mat);
            }
            
            // last row
            if(mat[n-1][j] == 1 && vis[n-1][j] ==0){
                // call dfs
                dfs(n-1,j,vis,mat);
            }
        }
        
        for(int i =0; i < n; i++){
            
            // first col
            if(mat[i][0]== 1 && vis[i][0]== 0){
                //call dfs
                dfs(i,0,vis,mat);
            }
            
            // last col
            if(mat[i][m-1] == 1 && vis[i][m-1] ==0){
                // call dfs
                dfs(i,m-1,vis,mat);
            }
        }
        
        int count = 0;
        for(int i =0 ; i< n ; i++){
            for(int j =0; j< m ; j++){
                if(mat[i][j] == 1 && !vis[i][j]){
                    count++;
                }
            }
        }
        
        return count;
    }