#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

// Using a struct for better readability
struct State {
    long long dist;
    int u;
    int coupon_used;

    // Priority queue is a max-heap, so we flip the comparison for min-heap
    bool operator>(const State& other) const {
        return dist > other.dist;
    }
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<pair<int, long long>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // dp[node][0] = min dist without coupon, dp[node][1] = with coupon used
    vector<vector<long long>> dp(n + 1, vector<long long>(2, inf));
    priority_queue<State, vector<State>, greater<State>> pq;

    dp[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        State top = pq.top();
        pq.pop();

        long long d = top.dist;
        int u = top.u;
        int used = top.coupon_used;

        // Standard Dijkstra optimization: skip if we found a better path already
        if (d > dp[u][used]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            long long w = edge.second;

            // Case 1: Don't use a coupon on this edge
            if (dp[v][used] > d + w) {
                dp[v][used] = d + w;
                pq.push({dp[v][used], v, used});
            }

            // Case 2: Use a coupon on this edge (only if we haven't used one yet)
            if (used == 0) {
                if (dp[v][1] > d + w / 2) {
                    dp[v][1] = d + w / 2;
                    pq.push({dp[v][1], v, 1});
                }
            }
        }
    }

    cout << min(dp[n][0], dp[n][1]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}