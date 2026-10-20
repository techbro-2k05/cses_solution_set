//BeginCodeSnip{C++ Short Template}
#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
//EndCodeSnip

/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1],
 * and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */

struct FT {
    vector<ll> s;
    FT(int n) : s(n,0) {}
    void update(int pos, ll dif) {  // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) {  // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
        return res;
    }
};

const int mx = 2e5 + 1;

vi adj[mx];
int A[mx];
int st[mx];
int en[mx];
int timer = 0;
FT ft(mx + 1);

void dfs(int x, int p) {  // euler tour
    st[x] = timer++;
    for (const int &e : adj[x])
        if (e != p) dfs(e, x);
    en[x] = timer -1;
}

int main() {
    setIO();

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) cin >> A[i];

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 0);
    // for(int i=1;i<=n;i++){
    //     cout<<st[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<en[i]<<" ";
    // }
    // cout<<endl;
    for (int i = 1; i <= n; i++) {
        ft.update(st[i], A[i]);
        ft.update(en[i] + 1, -A[i]);
    }

    for (int i = 0; i < q; i++) {
        int type, s;
        cin >> type >> s;
        if (type == 1) {
            int x;
            cin >> x;
            ft.update(st[s], x - A[s]);
            ft.update(en[s] + 1, -(x - A[s]));  // increment by 1
            A[s] = x;
        } else {
            cout << ft.query(st[s] + 1) << '\n';
        }
    }
}