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
    int n,q,d; 
    cin>>n>>q;
    int p[31][n+1]; 
    for(int i=0;i<=n;i++){
        for(int j=0;j<31;j++){
            p[j][i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>p[0][i];
    }
    for(int i=1;i<=30;i++){
        for(int j=1;j<=n;j++){
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
    while(q--){
        int x,k;
        cin>>x>>k;  
        // cout<<x<<" "<<k<<endl;
        int jp=0;
        while(k>0){
            if(k&1){
                x=p[jp][x];
                // cout<<x<<" ";
            }
            jp+=1; 
            k>>=1;
        }
        // cout<<endl;
        if(x==0){
            cout<<"-1"<<endl;
        }
        else{
            cout<<x<<endl;
        }
        
    }
    
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