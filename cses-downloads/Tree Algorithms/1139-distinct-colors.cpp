#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 200005;
vector <int> graph2[N];
set<int>color_present[N];  
vector<int>distinct_color(N,0);
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
vector<int>curr_comp(N,0);
int centroid=-1;
int allowed_nodes=0;
int n, m; 
void dfs(int vertex,int parents){
    visited[vertex]=true;
    // curr_comp.push_back(vertex);
    color_present[vertex].insert(curr_comp[vertex]);
    for(auto child: graph2[vertex]){
        if(child!=parents){
            dfs(child,vertex);
            if(color_present[vertex].size()<color_present[child].size()){
                swap(color_present[vertex],color_present[child]);
            }
            for(auto i: color_present[child]){
                color_present[vertex].insert(i);
            }
        }
    }
    distinct_color[vertex]=color_present[vertex].size();
}


void solve() {
    cin >> n;
    m=n-1; 
    // allowed_nodes=n/2; 
    for (int i = 0; i <= n; i++) {
        graph2[i].clear();
        visited[i] = false;
        p_parent[i] = 0;
    }
    for(int i=1;i<=n;i++){
        cin>>curr_comp[i];
    }
    for (int i = 0; i < m; i++) {
        int v1, v2;  
        cin >> v1 >> v2;
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }
    dfs(1,0);
    for (int i = 1; i <= n; i++) {
        cout<<distinct_color[i]<<" ";
    }
    cout<<endl;

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