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
// O(log(N))-> binary exponentation
struct TwoSatSolver {
    int n_vars;
    int n_vertices;
    vector<vector<int>> adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    TwoSatSolver(int _n_vars) : n_vars(_n_vars), n_vertices(2 * n_vars), adj(n_vertices), adj_t(n_vertices), used(n_vertices), order(), comp(n_vertices, -1), assignment(n_vars) {
        order.reserve(n_vertices);
    }
    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n_vertices, false);
        for (int i = 0; i < n_vertices; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n_vertices, -1);
        for (int i = 0, j = 0; i < n_vertices; ++i) {
            int v = order[n_vertices - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n_vars, false);
        for (int i = 0; i < n_vertices; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated 
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }
};

int main(){
    int n,m;
    cin>>n>>m; 
    TwoSatSolver solver(m);
    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        bool sign=(x=='-'); 
        int a;
        cin>>a;
        a--;
        bool sign_2;
        cin>>x; 
        sign_2=(x=='-');
        int b;
        cin>>b;
        b--;
        solver.add_disjunction(a,sign,b,sign_2);
    }
    bool st=solver.solve_2SAT();
    if(st==false){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for(auto i: solver.assignment){
        if(i==1){
            cout<<"+";
        }
        else{
            cout<<"-";
        }
        // cout<<<<" ";
    }
    cout<<endl;

}
