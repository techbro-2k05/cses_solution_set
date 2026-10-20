#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(vector<int>& data) {
        n = data.size();
        tree.resize(2 * n, INT_MAX);
        build(data);
    }

    void build(vector<int>& data) {
        // Initialize leaves
        for (int i = 0; i < n; i++) {
            tree[n + i] = data[i];
        }
        // Build internal nodes
        for (int i = n - 1; i > 0; i--) {
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update(int index, int value) {
        index += n; // Move to the leaf node
        tree[index] = value; // Update leaf value
        index /= 2; // Move to parent
        while (index >= 1) { // Propagate updates up
            tree[index] = min(tree[2 * index], tree[2 * index + 1]);
            index /= 2;
        }
    }

    int query(int l, int r) {
        l += n; // Move to the correct leaf range
        r += n;
        int res = INT_MAX;
        while (l < r) {
            if (l % 2 == 1) { // If left index is odd, include it
                res = min(res, tree[l]);
                l++;
            }
            if (r % 2 == 1) { // If right index is odd, include previous
                r--;
                res = min(res, tree[r]);
            }
            l /= 2; // Move to parent
            r /= 2;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Build the segment tree
    SegmentTree segTree(a);

    // Process queries
    while (q--) {
        int oper, l, r;
        cin >> oper >> l >> r;
        if (oper == 2) { // Range Minimum Query
            cout << segTree.query(l - 1, r) << "\n"; // Convert 1-based index to 0-based
        } else { // Update Operation
            segTree.update(l - 1, r); // Convert to 0-based index
        }
    }

    return 0;
}
