// ============================================================
// Phase 7: Graphs
// Topics: BFS/DFS, Dijkstra, topological sort, DSU, Kruskal's
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ---------- BFS & DFS ----------
void bfs(int src, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (!visited[v]) { visited[v] = true; q.push(v); }
    }
}
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]) dfs(v, adj, visited);
}

// ---------- Dijkstra's Algorithm ----------
vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// ---------- Topological Sort — Kahn's Algorithm ----------
vector<int> topoSort(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++)
        for (int v : adj[u]) indegree[v]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--indegree[v] == 0) q.push(v);
    }
    return order;
}

// ---------- Disjoint Set Union (DSU) ----------
class DSU {
    vector<int> parent, rank_;
public:
    DSU(int n) : parent(n), rank_(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
        return true;
    }
};

// ---------- Kruskal's Algorithm (MST) ----------
int kruskalMST(int V, vector<array<int,3>>& edges) {  // {weight, u, v}
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    int mstWeight = 0;
    for (auto& e : edges) {
        int w = e[0], u = e[1], v = e[2];
        if (dsu.unite(u, v)) mstWeight += w;
    }
    return mstWeight;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2}; adj[1] = {3}; adj[2] = {3}; adj[3] = {4};

    vector<bool> visited(V, false);
    bfs(0, adj, visited);
    cout << "BFS visited count: " << count(visited.begin(), visited.end(), true) << "\n";

    auto order = topoSort(V, adj);
    cout << "Topo order: ";
    for (int x : order) cout << x << " ";
    cout << "\n";

    vector<array<int,3>> edges = {{1,0,1},{2,1,2},{3,0,2},{4,2,3}};
    cout << "MST weight: " << kruskalMST(4, edges) << "\n";

    return 0;
}
