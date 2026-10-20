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
    int n, mq;
    cin >> n >> mq;

    // Reset values
    // timer = 0;
    fill(fenwick.begin(), fenwick.begin() + n + 1, 0);
    vector<long long int>axe(n+1,0ll); 
    for(int i=1;i<=n;i++){
        cin>>axe[i];
    }
    for(int i=1;i<=n;i++){
        update(i,axe[i],n);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<fenwick[i]<<" ";
    // }
    while(mq--){
        // int oper; 
        // cin>>oper; 
        // if(oper==1){
        //     int a;
        //     long long b; 
        //     cin>>a>>b;
        //     update(a,b,n);
        // }
        int oper=2;
        if(oper==2){
            int a;int b; 
            cin>>a>>b; 
            cout<<range_query(a,b)<<"\n";
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
