#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100005;
vector<int> graph2[N];
bool visited[N];
vector<int> weight(N, 1000);  // Stores min operations to reach x from 1
int p_parent[N];
vector<int> a; 
vector<int> dp;
vector<int> weights;
vector<int> values;
vector<long long int>factorials;
bool ans=false;
bool check_zero=false;
void dfs(int vertex, int parent){
    visited[vertex]=true; 
    if(ans!=true){
        for(auto child: graph2[vertex]){
        if(ans==true){
            break;
        }
        if(visited[child]==true and child!=parent){
            ans=true;
            factorials.push_back(child);
            check_zero=true;
            break;
        }
        else if(not visited[child]){
            dfs(child,vertex);
        }
        }
    }
    if(ans==true){
        if(check_zero){
           factorials.push_back(vertex); 
        }
        if(vertex==factorials.front()){
            check_zero=false;
        }
    }
}


void solve() {
    int n,m;
    cin>>n>>m; 
    for(int i=1;i<=n;i++){
        graph2[i].clear();
    }
    for(int i=1;i<=m;i++){
        int v1,v2; 
        cin>>v1>>v2; 
        graph2[v1].push_back(v2); 
        graph2[v2].push_back(v1); 
    }
    for(int source=0;source<=n;source++){
        if(not visited[source]){
            dfs(source,0);
    if(ans){
    // cout<<source<<endl;
    cout<<factorials.size()<<endl; 
    for(auto i: factorials){
    cout<<i<<" ";
    }
    cout<<endl;
    return;
    }
        }
    
    }
        cout<<"IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
