#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5;

int n, m;
vector<int> seg(4 * MAXN), h(MAXN);

// Build segment tree
void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = h[l];
    } else {
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }
}

// Update a room after placing a group
void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        seg[node] -= val;
    } else {
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);
        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }
}

// Query: Find first index with capacity >= val
int query(int node, int l, int r, int val) {
    if (seg[node] < val) return -1; // no such room
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (seg[2 * node] >= val)
        return query(2 * node, l, mid, val);
    else
        return query(2 * node + 1, mid + 1, r, val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    build(1, 1, n);

    while (m--) {
        int x;
        cin >> x;
        int idx = query(1, 1, n, x);
        if (idx == -1)
            cout << 0 << ' ';
        else {
            cout << idx << ' ';
            update(1, 1, n, idx, x);
        }
    }
    cout << '\n';

    return 0;
}
