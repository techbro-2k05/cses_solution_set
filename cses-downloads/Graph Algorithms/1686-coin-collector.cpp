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
    int n,m;
    cin>>n>>m; 
    vis.resize(n+1,0);
    vector<long long> coins(n+1,0);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }   
    vector<vector<int>>graph(n+1);
    vector<vector<int>>rev(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        rev[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(not vis[i]){
            // cout<<i<<": ";
            // vis[i]=true;
            dfs(graph,i);
        }
    }
    // cout<<endl;
    for(int i=1;i<=n;i++){
        vis[i]=false;
    }
    vector<int>scc_id(n+1,0);
    vector<long long>money(n+1,0ll);
    int c=1;
    while(!vert.empty()){
        int p=vert.top();
        // cout<<p<<" ";
        vert.pop();
        if(scc_id[p]!=0){
            // cout<<"helo";
            continue;
        }
        // now.clear();
        dfs_2(rev,p);
        while(!now.empty()){
            scc_id[now.top()]=c;
            money[c]+=coins[now.top()-1];
            now.pop();
        }
        c+=1;
    }
    vector<vector<int>>condensed_graph(c);
    for(int i=1;i<=n;i++){
        for(auto j: rev[i]){
            if(scc_id[i]!=scc_id[j]){
                condensed_graph[scc_id[i]].push_back(scc_id[j]);
            }
        }
    }
    vector<long long>dp(c,0ll);
    long long ans=0; 
    for(int i=1;i<c;i++){
        if(dp[i]==0){
            dp[i]=dfs_3(condensed_graph,dp,money,i);
            ans=max(ans,dp[i]);   
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