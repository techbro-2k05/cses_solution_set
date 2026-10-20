#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const int N = 200005;
vector <int> graph2[N];
bool visited[N];
int leaf_node=0; 
int dp[2][N];// 0 for child connection, 1 for parent connection 
int parent_noleafchild_node=0;   
void solve() {
    int n; 
    cin>>n; 
    vector<int>destination(n+1,0); 
    vector<int>cycle_length(n+1,0); 
    for(int i=0;i<=n;i++){
        visited[i]=false; 
        if(i!=0){
            cin>>destination[i];
        }
    }
    // for(auto i: destination){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    vector<int> stor_path; 
    for(int i=1;i<=n;i++){
        if(visited[i]==true){
            continue;
        }
        if(not visited[i]){
            int num=i; 
            stor_path.clear();
            stor_path.push_back(num);
            while(not visited[num]){
                visited[num]=true; 
                num=destination[num];
                stor_path.push_back(num);
            }
            if(cycle_length[stor_path.back()]==0){
                int cycle_len=1;
                if(stor_path.size()>=2){
                    for(int i=stor_path.size()-2;i>=0;i--){
                    if(stor_path.back()==stor_path[i]){
                        for(int j=i;j<stor_path.size()-1;j++){
                            cycle_length[stor_path[j]]=cycle_len;
                        }
                        for(int j=0;j<i;j++){
                            cycle_length[stor_path[j]]=cycle_len+i-j;
                            // cout<<stor_path[j]<<cycle_length[stor_path[j]]<<endl;
                        }
                        break;
                    }
                    else{
                        cycle_len++;
                    }
                    }
                }
            }
            else{
                int length=stor_path.size();
                // cout<<"yaay"<<i<<endl;
                for(int i=0;i<stor_path.size()-1;i++){
                    cycle_length[stor_path[i]]=cycle_length[stor_path.back()]+length-i-1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<cycle_length[i]<<" ";
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