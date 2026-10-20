#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 100005;
vector <int> graph2[N];
vector<int>p_parent(N,0);

int depth[N];
int leaf_node=0; 
int assigned_val[N];
int dp[2][N];// 0 for child connection, 1 for parent connection 
int parent_noleafchild_node=0;
bool odd_cycle_length=false;
void display(int n){
    for(int i=0;i<=n;i++){
        cout<<"vertices of "<<i<<":\n";
        for(int j=0;j<graph2[i].size();j++){
            cout<<graph2[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int p=31; 
vector<long long int> power_31; 
void lets_find(int n){
    // int n=1000006;
    int mods=1000000007; 
    long long curr=1ll;
    for(int i=0;i<=n;i++){
        power_31.push_back(curr);
        curr*=p; 
        curr%=mods; 
    }
}
bool visited[N];
vector<int>curr_comp;
void dfs(int vertex,int parents){
    visited[vertex]=true; 
    curr_comp.push_back(vertex); 
    for(auto child: graph2[vertex]){
        if(child!=parents){ 
            depth[child]=depth[vertex]+1; 
            dfs(child,vertex);
        } 
    }
}


void solve() {
    int n, m; 
    cin >> n >> m; 

    for (int i = 0; i <= n; i++) {
        graph2[i].clear();
        visited[i] = false;
        p_parent[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int v1, v2;  
        cin >> v1 >> v2;
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }

    if (n == 1) {
        cout << "1\n1\n";
        return;
    }

    queue<int> qp; 
    qp.push(1); 
    visited[1] = true; // FIXED: mark the starting node as visited

    while (!qp.empty()) {
        int p = qp.front(); 
        qp.pop(); 

        for (auto child : graph2[p]) {
            if (!visited[child]) {
                visited[child] = true;
                p_parent[child] = p;
                qp.push(child);
            }            
        }
    }

    if (!visited[n]) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> path;
    int curr = n;
    while (curr != 0) {
        path.push_back(curr); 
        curr = p_parent[curr];
    } 

    reverse(path.begin(), path.end());

    cout << path.size() << "\n"; 
    for (int node : path) {
        cout << node << " ";
    }
    cout << "\n";
}

  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    
    return 0;
}