#include <bits/stdc++.h>
using namespace std;

#define inf 1e18
//answer[v]=answer[p]-(sum_depth[v]+sub_tree[v])+sum_depth[v]+n-sub_tree[v];
//kosaraju -> scc
stack<int>vert;
vector<int>vis;
void dfs(vector<vector<int>> &graph,int v){
    // cout<<v<<" ";
    vis[v]=true;
    for(auto i: graph[v]){
        if(not vis[i]){
            dfs(graph,i);
        }
    }
    vert.push(v);
}
stack<int>now;
void dfs_2(vector<vector<int>> &graph,int v){
    vis[v]=true;
    now.push(v);
    for(auto i: graph[v]){
        if(not vis[i]){
            dfs_2(graph,i);
        }
    }
}

long long dfs_3(vector<vector<int>>&graph, vector<long long>&dp, vector<long long>&money, int v){
    if(dp[v]!=0ll){
        return dp[v];
    }
    dp[v]=money[v];
    for(auto i: graph[v]){
        dp[v]=max(dp[v],money[v]+dfs_3(graph,dp,money,i));
    }
    return dp[v];
}
void solve() {
    int n,k;
    cin>>n>>k; 
    vector<vector<char>>bits(n,vector<char>(k));
    vector<int>number;
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=0;j<k;j++){
            cin>>bits[i][j];
            // cout<<bits[i][j]<<" ";
            c<<=1;
            if(bits[i][j]=='1'){
                c+=1;
            }
        }
        // cout<<endl;
        number.push_back(c);
    }
    int ans=k;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=min(ans, __builtin_popcount(number[i]^number[j]));
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin>>t;
    // while(t--)
    solve();
    return 0;
}