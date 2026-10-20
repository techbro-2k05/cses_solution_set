#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fori(i,a,b) for(int i=a; i<b;i++)
#define Y { cout <<"YES"<< endl;}
#define NN { cout <<"NO"<< endl;}
#define N 100005
vector<int>graph2[N];
const int mod = 1e9+7;
bool visited[N];
vector<int>dp(N,0);

void dfs(int vertex,int n){
    visited[vertex]=true; 
    for(auto child: graph2[vertex]){
        if(not visited[child]){
            dfs(child,n);
        }
        dp[vertex]+=dp[child];
        dp[vertex]%=mod; 
    }
    if(vertex==n){
        dp[vertex]=1;
        return;
    }
}


void solve(){
    int n,m; 
    cin>>n>>m; 
    for(int i=0;i<=n;i++){
        graph2[i].clear();
        visited[i]=false;
        dp[i]=0; 
    }
    for(int i=0;i<m;i++){
        int v1,v2; 
        cin>>v1>>v2; 
        graph2[v1].push_back(v2); 
    }
    dfs(1,n);
    cout<<dp[1]<<endl;
}
 
int main(){
    fastio(); 
    int t;
    t=1; 
    // cin>>t;
    while(t--)
    solve();

}