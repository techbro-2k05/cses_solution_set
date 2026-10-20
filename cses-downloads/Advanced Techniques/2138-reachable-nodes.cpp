#include <bits/stdc++.h>

using namespace std;

const int maxN = 50001;
bitset<maxN> ans[maxN];
vector<int> adj[maxN + 1];

int main()
{
    // Sample Input
    int n,m;
    cin>>n>>m; 
    vector<vector<int> > edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    // vector to store the indegree of transpose graph
    int indeg[n + 1] = {};
    // Store the rreverse edges along with the indegrees
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][1]].push_back(edges[i][0]);
        indeg[edges[i][0]] += 1;
    }
    // queue to keep track of all nodes with indegree = 0
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            // Set the ith bit of bitset of node i
            ans[i].set(i);
            // Push the ith node to the queue
            q.push(i);
        }
    }
    // Iterate till the queue is not empty
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // Visit all the neighbours of the current node
        for (int v : adj[u]) {
            // Use the reachable nodes of the children to
            // mark the reachable nodes of the current node
            ans[v] |= ans[u];
            indeg[v]--;
            // If the indegree of the neighbouring nodes
            // become 0, push the neighbouring node to the
            // queue
            if (indeg[v] == 0) {
                ans[v].set(v);
                q.push(v);
            }
        }
    }
    // The count of reachable nodes of ith node is the
    // number of set bits in ith bitset
    for (int i = 1; i <= n; i++)
        cout << ans[i].count() << " ";
}