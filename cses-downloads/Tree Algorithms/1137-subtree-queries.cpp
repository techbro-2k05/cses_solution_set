#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 200005;
vector<int> graph[N];
vector<ll> weight(N);
int entry[N], exit_time[N], timer = 0;
vector<ll> fenwick(N, 0);
int parent[N];

// Fenwick Tree functions
void update(int i, ll val, int n) {
    for (; i <= n; i += (i & -i))
        fenwick[i] += val;
}

ll query(int i) {
    ll sum = 0;
    for (; i > 0; i -= (i & -i))
        sum += fenwick[i];
    return sum;
}

ll range_query(int l, int r) {
    return query(r) - query(l - 1);
}

// Euler Tour DFS
void dfs(int node, int par) {
    entry[node] = ++timer;
    parent[node] = par;
    update(entry[node], weight[node], N); // Store weight in Fenwick Tree
    
    for (int child : graph[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
    
    exit_time[node] = timer;
}

void solve() {
    int n, m;
    cin >> n >> m;

    // Reset values
    timer = 0;
    fill(fenwick.begin(), fenwick.begin() + n + 1, 0);
    for (int i = 1; i <= n; i++) graph[i].clear();

    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);

    while (m--) {
        int type;
        cin >> type;

        if (type == 1) {
            int v;
            ll new_value;
            cin >> v >> new_value;
            ll diff = new_value - weight[v];
            weight[v] = new_value;
            update(entry[v], diff, N);
        } else {
            int v;
            cin >> v;
            cout << range_query(entry[v], exit_time[v]) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
