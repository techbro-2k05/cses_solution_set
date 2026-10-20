#include <bits/stdc++.h>
using namespace std;
// __gcd(n,m)
#define N 200005
// bool visited[N];
int depth[N];
int height[N];
long long int sum[N];
int even[N];
int cycle=0;
vector<int> graph2[N];
vector<int> parent(N,0);
vector<vector<int>> cc;
vector<int> curr_comp;
void display(int n){
    for(int i=0;i<=n;i++){
        cout<<"vertices of "<<i<<":\n";
        for(int j=0;j<graph2[i].size();j++){
            cout<<graph2[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void dfs_2(int vertex,int parent){
    if(parent==0){
        depth[vertex]=0;
    }
    else{
        depth[vertex]=depth[parent]+1;
    }
    if(graph2[vertex].size()==1 && graph2[vertex][0]==parent){
        height[vertex]=0;//does not cover a tree with root as only node
    }
    for(int child: graph2[vertex]){
        if(child==parent){
            continue;
        }
        else{
            dfs_2(child,vertex);
            depth[child]=depth[vertex]+1;
            height[vertex]=max(height[vertex],height[child]+1);
            // depth[vertex]=depth[parent]+1;
        }
    }
}
void dfs(int vertex,int parents){
    for(int child: graph2[vertex]){
        if(child==parents){
            continue;
        }
        else{
            dfs(child,vertex);
            // parent[child]=vertex;
        }
    }
    parent[vertex]=parents;
}
//finding sum of subtree;
void dfs_sum(int vertex,int parent){
    for(int child: graph2[vertex]){
        if(child==parent){
            continue;
        }
        else{
            dfs_sum(child,vertex);
            // depth[child]=depth[vertex]+1;
            sum[vertex]+=sum[child];
            // depth[vertex]=depth[parent]+1;
        }
    }
    sum[vertex]+=vertex;
}

//finding number of even in subtree;
void dfs_even(int vertex,int parent){
    for(int child: graph2[vertex]){
        if(child==parent){
            continue;
        }
        else{
            dfs_even(child,vertex);
            // depth[child]=depth[vertex]+1;
            even[vertex]+=even[child];
            // depth[vertex]=depth[parent]+1;
        }
    }
    if(vertex%2==0)
    even[vertex]+=1;
}

int main() {
    for (int i = 0; i < N ; i++){
        depth[i]=0;
        height[i]=0;
        sum[i]=0;
        even[i]=0;
        // parent[i]=0;
    }
    
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }
    dfs_2(1,0);
    int max=1;
    for(int i=1;i<=n;i++){
        if(depth[max]<=depth[i]){
            max=i;
        }
    }
    for(int i=1;i<=n;i++){
        depth[i]=0;
    }
    dfs_2(max,0);
    int diameter=0;
    for(int i=1;i<=n;i++){
        if(diameter<depth[i]){
            diameter=depth[i];
        }
    }
    cout<<diameter<<"\n";
    // int q;
    // cin>>q;
    // dfs_sum(1,0);
    // dfs_even(1,0);
    // cout<<"\n";
    // while(q--){
    //     int v1;
    //     cin>>v1;
    //     cout<<sum[v1]<<endl;
    //     cout<<even[v1]<<endl;
    //     cout<<endl;
    // }
    // //lca-> by finding parent path till root node
    // dfs(1,0);
    // int v1,v2;
    // cin>>v1>>v2;
    // vector<int>store_1;
    // store_1.push_back(v1);
    // vector<int>store_2;
    // while(parent[v1]!=0){
    //     store_1.push_back(parent[v1]);
    //     v1=parent[v1];
    // }
    // store_2.push_back(v2);
    // while(parent[v2]!=0){
    //     store_2.push_back(parent[v2]);
    //     v2=parent[v2];
    // }
    // v1=store_1[0];
    // v2=store_2[0];
    // int length_1=store_1.size()>store_2.size()?store_2.size():store_1.size();
    // reverse(store_1.begin(),store_1.end());
    // reverse(store_2.begin(),store_2.end());
    // int lca=0;
    // for(int i=0;i<length_1;i++){
    //     if(store_2[i]==store_1[i]){
    //         lca=store_2[i];
    //     }
    //     else{
    //         break;
    //     }
    // }
    // cout<<lca<<endl;



}