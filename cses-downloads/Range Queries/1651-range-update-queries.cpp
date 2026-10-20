#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

vector<ll> tree;

void build(vector<ll>& arr, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];  // Leaf node
    } else {
        int mid = (start + end) / 2;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Sum of children
    }
}

void update(int node, int start, int end, int idx, long long value) {
    if (start == end) {
        tree[node] += value; // Update leaf node
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node + 1, start, mid, idx, value);
        else
            update(2 * node + 2, mid + 1, end, idx, value);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Update parent
    }
}

long long query(int node, int start, int end, int l, int r) {
    if (r < start || l > end) return 0; // No overlap
    if (l <= start && end <= r) return tree[node]; // Total overlap

    int mid = (start + end) / 2;
    long long left_sum = query(2 * node + 1, start, mid, l, r);
    long long right_sum = query(2 * node + 2, mid + 1, end, l, r);
    return left_sum + right_sum; // Partial overlap
}

void build_tree(vector<ll>& arr, int n) {
    tree.clear();
    tree.resize(4 * n, 0);
    build(arr, 0, 0, n - 1);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> diff(n, 0ll);
    diff[0] = a[0];
    for (int i = 1; i < n; i++) {
        diff[i] = a[i] - a[i - 1];
    }

    build_tree(diff, n);

    while (m--) {
        int oper;
        cin >> oper;
        if (oper == 1) {
            int left, right;
            long long u;
            cin >> left >> right >> u;
            left--; right--; 

            update(0, 0, n - 1, left, u);
            if (right + 1 < n) {
                update(0, 0, n - 1, right + 1, -u);
            }
        } else {
            int k;
            cin >> k;
            k--;
            cout << query(0, 0, n - 1, 0, k) << endl;
        }
    }
}

int main() {
    fast_cin();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
