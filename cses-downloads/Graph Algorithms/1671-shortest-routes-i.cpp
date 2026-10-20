#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define inf INT_MAX

vector<pair<int, long long>> graph2[N];
int n, m;
// o(v+Elog(v))
void dijkstra(int source) {
    vector<long long> distance(N,-1ll);
    vector<int> visited(N, 0);
    vector<int> parent(N, -1);
    set<pair<long long, int>> st;

    // Initialize the source
    st.insert({0ll, source});  // {distance, vertex}
    distance[source] = 0ll;

    while (!st.empty()) {
        auto node = *st.begin();
        st.erase(st.begin());

        int v = node.second;
        long long dist = node.first;

        if (visited[v]) continue;
        visited[v] = 1;

        for (auto child : graph2[v]) {
            int child_v = child.first;
            long long w = child.second;

            // Relaxation
            if (distance[child_v]==-1ll || distance[v] + w < distance[child_v]) {
                st.erase({distance[child_v], child_v}); // Remove outdated value
                distance[child_v] = distance[v] + w;
                parent[child_v] = v;
                st.insert({distance[child_v], child_v}); // Insert updated value
            }
        }
    }

    // Print results
    for (int i = 1; i <= n; i++) {
        cout << (distance[i] == -1ll? "Infinity" : to_string(distance[i])) << " ";
    }
    cout<<endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph2[v1].push_back({v2, w});
    }

    dijkstra(1);
}
