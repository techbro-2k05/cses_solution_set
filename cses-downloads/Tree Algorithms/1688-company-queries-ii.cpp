#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define N 300001
vector<int> graph2[N];
vector<int> p_parent(N, 0);
vector<int> store_eucl;
vector<int> store_eucl_height;
vector<int> first_occ(N, -1);
bool visited[N];
int depth[N];
vector<int> segment_tree;

void dfs(int vertex, int parent) {
    visited[vertex] = true;
    for (auto i : graph2[vertex]) {
        if (i != parent && !visited[i]) {
            p_parent[i] = vertex;
            store_eucl.push_back(i);
            depth[i] = depth[vertex] + 1;
            store_eucl_height.push_back(depth[i]);
            dfs(i, vertex);
            store_eucl.push_back(vertex);
            store_eucl_height.push_back(depth[vertex]);
        }
    }
}

void build_tree(int node, int start, int end) {
    if (start == end) {
        segment_tree[node] = start;
    } else {
        int mid = (start + end) / 2;
        build_tree(2 * node + 1, start, mid);
        build_tree(2 * node + 2, mid + 1, end);
        segment_tree[node] = (store_eucl_height[segment_tree[2 * node + 1]] < store_eucl_height[segment_tree[2 * node + 2]])
                                 ? segment_tree[2 * node + 1]
                                 : segment_tree[2 * node + 2];
    }
}

int query(int node, int start, int end, int L, int R) {
    if (L > end || R < start) return -1;
    if (L <= start && end <= R) return segment_tree[node];
    int mid = (start + end) / 2;
    int left = query(2 * node + 1, start, mid, L, R);
    int right = query(2 * node + 2, mid + 1, end, L, R);
    if (left == -1) return right;
    if (right == -1) return left;
    return (store_eucl_height[left] < store_eucl_height[right]) ? left : right;
}

int find_lca(int u, int v) {
    int L = first_occ[u], R = first_occ[v];
    if (L > R) swap(L, R);
    int index = query(0, 0, store_eucl_height.size() - 1, L, R);
    return store_eucl[index];
}

void solve() {
    int n,q;
    cin >> n>>q;
    store_eucl.clear();
    store_eucl_height.clear();
    for (int i = 1; i <= n; i++) {
        graph2[i].clear();
        visited[i] = false;
        depth[i] = 1;
        first_occ[i] = -1;
    }
    for (int i = 2; i <= n; i++) {
        int v1, v2;
        cin >>v2;
        graph2[i].push_back(v2);
        graph2[v2].push_back(i);
    }
    store_eucl.push_back(1);
    store_eucl_height.push_back(1);
    dfs(1, 0);
    // for(auto i: store_eucl){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto i: store_eucl_height){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    int length = store_eucl_height.size();
     for (int i = 0; i < store_eucl_height.size(); i++) {
        if (first_occ[store_eucl[i]] == -1) {
            first_occ[store_eucl[i]] = i;
        }
    }
    segment_tree.resize(4 * length);
    build_tree(0, 0, length - 1);
    
    // int q;
    // cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << find_lca(u, v) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
