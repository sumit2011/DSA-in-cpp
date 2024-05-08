// dijkstra algorythm

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V);
    for (int i = 0; i < V; i++)
    {
        dist[i] = 1e9;
    }

    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int edgeweight = it[1];
            int adjnode = it[0];

            if (dis + edgeweight < dist[adjnode])
            {
                dist[adjnode] = dis + edgeweight;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }

    return dist;
}

// shortes path in undirected graph
// ques: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // Code here
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n + 1, 1e9), parent(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjnode = it.first;
            int edw = it.second;
            if (dis + edw < dist[adjnode])
            {
                dist[adjnode] = dis + edw;
                pq.push({dis + edw, adjnode});
                parent[adjnode] = node;
            }
        }
    }
    if (dist[n] == 1e9)
        return {-1};
    vector<int> path;
    int node = n;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    path.push_back(dist[n]);
    reverse(path.begin(), path.end());

    return path;
}