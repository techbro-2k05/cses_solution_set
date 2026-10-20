#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 200005;
set<int> graph2[N];
bool visited[N];
// vector<int> weights(N, 1e9);  // Stores min operations to reach x from 1
// set<pair<int,int>> gp_edges; // Stores edges satisfying given condition

void solve() {
    int n; 
    cin>>n; 
    map<long int,int>mp; 
    int start=1;
    int len=0;
    for(int i=1;i<=n;i++){
        long int k; 
        cin>>k; 
        if(mp[k]==0){
            mp[k]=i; 
        }
        else{
            if(mp[k]<start){
                mp[k]=i;
            }
            else{
                start=mp[k]+1;
                mp[k]=i; 
            }
        }
        len=max(len,i-start+1);
        // cout<<len<<" "<<start<<endl;
    }
    // len=max(len,n-start+1);
    cout<<len<<endl;   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}
