#include <bits/stdc++.h>
using namespace std;

#define N 510
#define INF 1e18 // Large constant instead of INT_MAX
long long dist[N][N];
int n, m, q;

int main() {
    cin >> n >> m >> q;

    // Initialize distance matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
        dist[b][a] = min(dist[b][a], w);
    }

    // Floyd-Warshall Algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Process queries
    while (q--) {
        int v1, v2;
        cin >> v1 >> v2;
        if (dist[v1][v2] == INF) {
            cout << "-1\n";
        } else {
            cout << dist[v1][v2] << "\n";
        }
    }

    return 0;
}
