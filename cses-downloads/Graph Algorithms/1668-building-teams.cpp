#include <bits/stdc++.h>
using namespace std;
// #define ll long long
 
const int N = 200005;
vector <int> graph2[N];
bool visited[N];
int depth[N];
int leaf_node=0; 
int assigned_val[N];
int dp[2][N];// 0 for child connection, 1 for parent connection 
int parent_noleafchild_node=0;
void display(int n){
    for(int i=0;i<=n;i++){
        cout<<"vertices of "<<i<<":\n";
        for(int j=0;j<graph2[i].size();j++){
            cout<<graph2[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool dfs(int vertex,int parents){
    visited[vertex]=true;
    bool ans=true; 
    for(auto child:graph2[vertex]){
        if(visited[child] and child!=parents and abs(depth[vertex]-depth[child])%2==0){
            return false;
        }
        else if(not visited[child]){
            depth[child]=depth[vertex]+1;
            if(assigned_val[vertex]==1){
                assigned_val[child]=2;
            }
            else{
                assigned_val[child]=1;
            }
            ans&=dfs(child,vertex);
        }
    }
    return ans;
}


void solve() {
    int n; 
    cin>>n; 
    int m; 
    cin>>m;
    for(int i=0;i<=n;i++){
        graph2[i].clear(); 
        depth[i]=0;
        visited[i]=false;
        assigned_val[i]=1;
    }
    for(int i=0;i<m;i++){
        int v1,v2; 
        cin>>v1>>v2; 
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1); 
    }
    bool final_ans=true;
    for(int i=1;i<n;i++){
        if(not visited[i]){
            final_ans=dfs(i,0);
            if(final_ans==false){
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<assigned_val[i]<<" ";
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