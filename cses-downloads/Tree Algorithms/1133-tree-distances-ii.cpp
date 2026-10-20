#include <bits/stdc++.h>
using namespace std;

#define inf 1e18
vector<long long int>sub_tree;
vector<long long int>sum_depth;
void dfs(vector<vector<int>>&graph, int v, int parent){
    for(auto i: graph[v]){
        if(i==parent){
            continue;
        }
        dfs(graph,i,v);
        sub_tree[v]+=sub_tree[i];
        sum_depth[v]+=sum_depth[i];
        sum_depth[v]+=sub_tree[i];
    }
    sub_tree[v]++;
}

void dfs_2(vector<long long int>&answer, vector<vector<int>>&graph, int v, int parent, int n){
    if(parent!=0){
        answer[v]=answer[parent]-sub_tree[v]+n-sub_tree[v];
    }
    else{
        answer[v]=sum_depth[v];
    }
    for(auto i: graph[v]){
        if(i==parent){
            continue;
        }
        dfs_2(answer,graph,i,v,n);
    }
}

//answer[v]=answer[p]-(sum_depth[v]+sub_tree[v])+sum_depth[v]+n-sub_tree[v];

void solve() {
    int n;
    cin>>n;
    sub_tree.resize(n+1,0);
    sum_depth.resize(n+1,0);
    vector<vector<int>>graph(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(graph,1,0);
    vector<long long int>answer(n+1,0);
    dfs_2(answer,graph,1,0,n);
    for(int i=1;i<=n;i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}