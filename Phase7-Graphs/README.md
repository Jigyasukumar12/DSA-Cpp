# 🕸️ Phase 7: Graphs

![Duration](https://img.shields.io/badge/Duration-2.5_Weeks-blue) ![Difficulty](https://img.shields.io/badge/Difficulty-Advanced-orange) ![Status](https://img.shields.io/badge/Status-Not_Started-lightgrey)

> One of the highest-weightage topics in both interviews and competitive programming.

---

## 📊 Progress

```
Overall  [░░░░░░░░░░] 0%
```

## 🗂️ Topics

| # | Topic | Priority | Done |
|---|-------|----------|------|
| 1 | Representation — adjacency list/matrix | 🔴 High | ☐ |
| 2 | BFS + applications | 🔴 High | ☐ |
| 3 | DFS + applications | 🔴 High | ☐ |
| 4 | Connected components | 🔴 High | ☐ |
| 5 | Cycle detection (directed & undirected) | 🔴 High | ☐ |
| 6 | Topological sort — Kahn's + DFS-based | 🔴 High | ☐ |
| 7 | Dijkstra's algorithm | 🔴 High | ☐ |
| 8 | Bellman-Ford | 🟡 Medium | ☐ |
| 9 | Floyd-Warshall | 🟡 Medium | ☐ |
| 10 | Prim's algorithm (MST) | 🟡 Medium | ☐ |
| 11 | Kruskal's algorithm + DSU | 🔴 High | ☐ |

## 🧠 Key Concepts

- **BFS** — shortest path in unweighted graphs
- **Dijkstra** — shortest path in weighted graphs (non-negative weights), uses min-heap
- **DSU (Disjoint Set Union)** — union-find with path compression, essential for Kruskal's & cycle detection

## 💻 Important Code Snippets

### BFS & DFS (Adjacency List)
```cpp
void bfs(int src, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) { visited[v] = true; q.push(v); }
        }
    }
}

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]) dfs(v, adj, visited);
}
```

### Dijkstra's Algorithm
```cpp
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
```

### Topological Sort — Kahn's Algorithm (BFS)
```cpp
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
    return order;  // size < V means cycle exists
}
```

### Disjoint Set Union (DSU) — for Kruskal's & Cycle Detection
```cpp
class DSU {
    vector<int> parent, rank_;
public:
    DSU(int n) : parent(n), rank_(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;  // already connected — would form cycle
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
        return true;
    }
};
```

### Kruskal's Algorithm (MST)
```cpp
int kruskalMST(int V, vector<array<int,3>>& edges) {  // {weight, u, v}
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    int mstWeight = 0;
    for (auto& [w, u, v] : edges)
        if (dsu.unite(u, v)) mstWeight += w;
    return mstWeight;
}
```

## 📈 Problem Distribution (40 problems)

```
BFS/DFS Basics    [███████░░░] 25%
Topo Sort         [█████░░░░░] 15%
Shortest Path     [████████░░] 30%
MST/DSU           [██████░░░░] 20%
Misc Applications [███░░░░░░░] 10%
```

## ✅ Practice Checklist

- [ ] Implement BFS & DFS from scratch (both representations)
- [ ] Number of islands / connected components
- [ ] Detect cycle — directed & undirected graph
- [ ] Topological sort — both methods
- [ ] Dijkstra — implement + 5 problems
- [ ] Bellman-Ford — detect negative cycle
- [ ] Floyd-Warshall — all-pairs shortest path
- [ ] Kruskal's + DSU implementation
- [ ] Prim's algorithm

## ⬅️➡️ Navigation

**[← Phase 6: Heaps & Hashing](./PHASE_6_HEAPS_HASHING.md)** | **[Phase 8: Dynamic Programming →](./PHASE_8_DYNAMIC_PROGRAMMING.md)**
