// bfs of graph
// 0 based indexing
// gfg ques

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