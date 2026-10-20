#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 200005;
vector <int> graph2[N];
bool visited[N];
int leaf_node=0; 
int dp[2][N];// 0 for child connection, 1 for parent connection 
int parent_noleafchild_node=0; 
void dfs(int vertex,int parent){
    int child_comp=0;
    for(auto i: graph2[vertex]){
        if(i!=parent){
            dfs(i,vertex);
            child_comp+=dp[0][i];
        }
    }
    if(graph2[vertex].size()==1){
        dp[0][vertex]=0; 
        dp[1][vertex]=1;
        return;
    }
    if(parent!=0){
        dp[1][vertex]=child_comp+1;
    }
    else{
        dp[1][vertex]=child_comp;
    }
    for(auto i: graph2[vertex]){
        if(i!=parent){
            dp[0][vertex]=max(dp[0][vertex], child_comp-dp[0][i]+dp[1][i]);
        }
    }
}


void solve() {
    int n,m,d; 
    cin>>n;
    for(int i=0;i<=n;i++){
        dp[0][i]=0; 
        dp[1][i]=0;
    } 
    for(int i=2;i<=n;i++){
        int v1,v2; 
        cin>>v1>>v2; 
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }
    dfs(1,0); 
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[0][i]);
        ans=max(ans,dp[1][i]);
        // cout<<dp[0][i]<<" "<<dp[1][i]<<endl;
    }
    cout<<ans<<endl;
    
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
