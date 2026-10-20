#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 10005;
vector <int> graph2[N];

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
void solve() {
    string s; 
    cin>>s; 
    int n=s.length(); 
    if(n<2){
        cout<<0<<endl;
        return;
    }
    lets_find(n);
    vector<long long>forward_hashes(n); 
    vector<long long>backward_hases(n+1,0); 
    int mods=1000000007; 
    for(int i=0;i<n;i++){
        forward_hashes[i]=(s[i]-97);
        forward_hashes[i]*=power_31[i]; 
        forward_hashes[i]%=mods;
        if(i>0){
            forward_hashes[i]+=forward_hashes[i-1]; 
            forward_hashes[i]%=mods; 
        } 
    }
    for(int i=n-1;i>=0;i--){
        backward_hases[i]=backward_hases[i+1]*31;
        backward_hases[i]%=mods;  
        backward_hases[i]+=(s[i]-97);
        backward_hases[i]%=mods;  
    }
    int start=0;  
    vector<int>llp; 
    while(start<n-1){
        if(forward_hashes[start]==backward_hases[n-1-start]){
            llp.push_back(start+1);
        }
        start++;
    }
    for(auto i: llp){
        cout<<i<<" ";
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