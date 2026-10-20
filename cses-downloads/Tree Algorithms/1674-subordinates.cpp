#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
// __gcd(n,m)
#define N 200001
bool visited[N];
int cycle=0;
long long dp_value=0ll;
vector<int>p_parent(N,0);
vector<long int>final_ans(N,0);
vector<int> sub_child(N,0);
vector<int> graph2[N];
vector<char>directions(N,0);
vector<long int> a(N,0);
vector<int>primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,37,41};
int prime_non_divisor(long int n){
    for(auto i:primes){
        if(n%i!=0){
            return i;
        }
    }
    return 41;
}
// int value_compare=0;
void dfs(int vertex){
    for(auto i: graph2[vertex]){
        dfs(i);
        sub_child[vertex]+=sub_child[i]+1;
    }
}



void solve() {
    int n,m; 
    cin>>n; 
    for(int i=2;i<=n;i++){
        int p; 
        cin>>p;
        graph2[p].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<sub_child[i]<<" ";
    }
    cout<<endl;
}

int main() {
    // linearSieve(floor(pow(sqrt(10), 9)), primes, spf);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    int n=1000000;
    // cin>>t;
    while(t--){
        solve();
    }
}