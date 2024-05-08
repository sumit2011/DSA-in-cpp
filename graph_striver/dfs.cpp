
// Function to return a list containing the DFS traversal of the graph.

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
{

    vis[node] = 1;      // mark node visited
    ls.push_back(node); // list to store dfs traversal

    // traverse all its neighbours of the node
    for (auto i : adj[node])
    {
        // if non visited call dfs again
        if (!vis[i])
        {
            // recursive call
            dfs(i, adj, vis, ls);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    int vis[V] = {0}; // visited array
    int start = 0;
    vector<int> ls; // list to store dfs traversal
    dfs(start, adj, vis, ls);
    return ls;
}