

// bfs traversal
// vector<int> adj[]  -> adjacency list
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    int vis[V] = {0}; // visited arrray mark all element initially zero
    vis[0] = 1;       // marked visted  for 0
    queue<int> q;
    q.push(0);       // pushing starting node in the queue
    vector<int> bfs; // to store the bfs traversal of the graph
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node); // store the node in bfs

        // pushing the neighbors of the node in the queue if not visited
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                vis[i] = 1; // mark visited
                q.push(i);  // push the node in the queue
            }
        }
    }
    return bfs;
}

// space complexicity = O(3N) --> O(N)
// time complexicity = O(N) + O(2E)

// dfs traversal
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

// conversion from adjacency matrix to adjancency list
vector<int> adjList[V];
for (int i = 0; i < V; i++)
{
    for (int j = 0; j < V; j++)
    {
        if (adj[i][j] == 1 && i != j)
        {
            adjList[i].push_back(j);
            adjList[j].push_back(i);
        }
    }
}

// topological sort
vector<int> toposort(int v, vector<int> adj[])
{
    int indegree[v] = {0};
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return topo;
}