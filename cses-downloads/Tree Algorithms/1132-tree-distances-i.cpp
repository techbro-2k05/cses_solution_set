#include <bits/stdc++.h>
using namespace std;

#define inf 1e18
vector<int>p;
vector<int>depth;
void dfs(vector<vector<int>>&graph, int v, int parent){
    for(auto i: graph[v]){
        if(i==parent){
            continue;
        }
        p[i]=v;
        depth[i]=depth[v]+1;
        dfs(graph,i,v);
    }
}

void solve() {
    int n;
    cin>>n;
    p.resize(n+1,0);
    depth.resize(n+1,0);
    vector<vector<int>>graph(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(graph,1,0); 
    int m=1; 
    for(int i=2;i<=n;i++){
        if(depth[i]>depth[m]){
            m=i;
        }
    }
    // cout<<m<<endl;
    depth.clear();
    depth.resize(n+1,0);
    p[m]=0;
    dfs(graph,m,0);
    for(int i=1;i<=n;i++){
        if(depth[i]>depth[m]){
            m=i;
        }
    }
    int dia=depth[m];
    // cout<<m<<" "<<dia<<endl;
    // for(auto i: p){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    vector<int>answer(n+1,-1); 
    int x=0;
    while(m!=0){
        answer[m]=max(x,dia-x);
        m=p[m];
        x++;
    }
    for(int i=1;i<=n;i++){
        if(answer[i]!=-1){
            queue<int>qp; 
            qp.push(i);
            while(!qp.empty()){
                int y=qp.front();
                qp.pop();
                for(auto ik: graph[y]){
                    if(answer[ik]==-1){
                        answer[ik]=answer[y]+1;
                        qp.push(ik);
                    }
                }
            }
        }
    }
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