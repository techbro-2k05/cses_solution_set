#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// __gcd(n,m)
#define indexed_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define N 1000005
// int visited[N][N]={0};
const int mods_1= 1e9+7;
const int mods_2=998244353;//use this for string hashing
// vector<int>graph[N];

//for syntax
#define f(start,end) for(int i=start;i<end;i++)
#define fullf(start,end) for(int i=start;i<=end;i++)
#define f0(end) f(0,end)
#define f1(end) f(1,end)
#define fneg(end) for(int i=end;i>=0;i--)


//binary operations on 64 bits long long integer
#define bincount_leading_zero(x) __builtin_clzll(x)
#define bincount_trailing_zero(x) __builtin_ctzll(x)
#define bin_one_count(x) __builtin_popcountll(x)
#define bin_one_even_odd(x) __builtin_parityll(x)



//vector and map operations
#define pf push_front
#define pb push_back
#define ff first
#define ss second
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()


//for usual cf outputs
#define yes cout << "YES" << nl
#define no cout << "NO" << nl

//data-types
#define ll long long
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p32>> vvp32;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;

//O(1)
#define pb push_back
#define emb emplace_back
#define emf emplace_front
#define po pop_back
#define pf push_front
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define make_unique(x) \
    sort(all(x));      \
    (x).resize(unique(all(x)) - (x).begin());
//unique -> only starting elements unique followed by duplicates, not in sorted order(preserves og order)
#define minify(x, y) x = min(x, y) //same data type to be followed
#define maxify(x, y) x = max(x, y) //same data type to be followed
struct SegmentTree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = max(tree[x], v);
            return;
        }
        int mid = lx + (rx - lx) / 2;
        if (i < mid) {
            update(i, v, 2 * x + 1, lx, mid);
        } else {
            update(i, v, 2 * x + 2, mid, rx);
        }
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return tree[x];
        int mid = lx + (rx - lx) / 2;
        int s1 = query(l, r, 2 * x + 1, lx, mid);
        int s2 = query(l, r, 2 * x + 2, mid, rx);
        return max(s1, s2);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};
void solve() {
    int n;
    cin>>n; 
    vector<int>vp(n);
    vector<pair<int,int>>so(n);
    f0(n){
        cin>>vp[i];
        so[i]={vp[i],i};
    }
    sort(all(so));
    vector<int>left(n);
    vector<int>right(n); 
    stack<int>sp; 
    f0(n){
        int x=i+1; 
        while(!sp.empty() and vp[i]>=vp[sp.top()]){
            sp.pop();
        } 
        if(sp.empty()){
            left[i]=0;
        }  
        else{
            left[i]=sp.top()+1;
        }
        sp.push(i);
    }
    while(!sp.empty()){
        sp.pop();
    }

    for(int i=n-1;i>=0;i--){
        while(!sp.empty() and vp[i]>=vp[sp.top()]){
            sp.pop();
        } 
        if(sp.empty()){
            right[i]=n;
        }  
        else{
            right[i]=sp.top();
        }
        sp.push(i);
    }

    // for(auto i:left){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto i:right){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    SegmentTree stree;
    stree.init(n);
    vector<int> dp(n, 1);
    int overall_max = 0;

    // Step 2: DP evaluation using Range Maximum Query
    // Group identical heights to update the Segment Tree only after the batch is resolved
    int i = 0;
    while (i < n) {
        int j = i;
        // Find the range of all elements sharing the current minimum height
        while (j < n && so[j].first == so[i].first) {
            j++;
        }

        // Phase A: Calculate DP for the current batch of equal heights
        for (int k = i; k < j; k++) {
            int idx = so[k].second;
            int left_bound = left[idx];
            int right_bound = right[idx]; // right bound is exclusive in segment tree query

            // Query the maximum paths already written into the tree inside our boundary window
            int best_prev = stree.query(left_bound, right_bound);
            dp[idx] = 1 + best_prev;
            overall_max = max(overall_max, dp[idx]);
        }

        // Phase B: Commit the calculated DP values to the Segment Tree
        for (int k = i; k < j; k++) {
            int idx = so[k].second;
            stree.update(idx, dp[idx]);
        }

        i = j; // Move to the next unique height level
    }

    cout << overall_max << "\n";
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}