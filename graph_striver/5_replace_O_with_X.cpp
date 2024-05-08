// replace O's with X's in a given matrix
// gfg: https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat)
{
    // mark visited
    vis[row][col] = 1;

    // check for all 4 direction up ,right, down, left
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    int n = mat.size();    // row size
    int m = mat[0].size(); // column size

    // traverse in all 4 direction
    for (int i = 0; i < 4; i++)
    {
        // new row and new column
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
        {
            // recursive call
            dfs(nrow, ncol, vis, mat);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    // code here
    // n-> rows;
    // m-> col
    vector<vector<int>> vis(n, vector<int>(m, 0));
    // vector<vector<char>> temp = mat;

    // check first row and last row
    for (int j = 0; j < m; j++)
    {

        // first row
        if (mat[0][j] == 'O' && vis[0][j] == 0)
        {
            // call dfs
            dfs(0, j, vis, mat);
        }

        // last row
        if (mat[n - 1][j] == 'O' && vis[n - 1][j] == 0)
        {
            // call dfs
            dfs(n - 1, j, vis, mat);
        }
    }

    // check first and last column
    for (int i = 0; i < n; i++)
    {

        // first col
        if (mat[i][0] == 'O' && vis[i][0] == 0)
        {
            // call dfs
            dfs(i, 0, vis, mat);
        }

        // last col
        if (mat[i][m - 1] == 'O' && vis[i][m - 1] == 0)
        {
            // call dfs
            dfs(i, m - 1, vis, mat);
        }
    }

    // after checking boundaries mark all remaining Os with Xs in the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'O' && !vis[i][j])
            {
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
}