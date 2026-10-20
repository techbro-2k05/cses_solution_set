#include<bits/stdc++.h>
using namespace std; 
vector<vector<int>>chess;
vector<vector<bool>>visited;
int mods=1e9+7;
void find_ways_knight(int n){

}

int main(){
	int n;
	cin>>n; 
	chess.resize(n,vector<int>(n,mods));
	visited.resize(n,vector<bool>(n,false));
	chess[0][0]=0; 
	visited[0][0]=true;
	queue<pair<int,int>>qp;
	qp.push({0,0});
	while(!qp.empty()){
		int x=qp.front().first,y=qp.front().second;
		int val=chess[x][y];
		qp.pop(); 
		if(x-2>=0 and y-1>=0 and (not visited[x-2][y-1])){
			chess[x-2][y-1]=val+1;
			visited[x-2][y-1]=true;
			qp.push({x-2,y-1});
		}
		if(y-2>=0 and x-1>=0 and (not visited[x-1][y-2])){
			chess[x-1][y-2]=val+1;
			visited[x-1][y-2]=true;
			qp.push({x-1,y-2});
		}
		if(x-2>=0 and y+1<n and (not visited[x-2][y+1])){
			chess[x-2][y+1]=val+1;
			visited[x-2][y+1]=true;
			qp.push({x-2,y+1});
		}
		if(y+2<n and x-1>=0 and (not visited[x-1][y+2])){
			chess[x-1][y+2]=val+1;
			visited[x-1][y+2]=true;
			qp.push({x-1,y+2});
		}
		if(x+2<n and y-1>=0 and (not visited[x+2][y-1])){
			chess[x+2][y-1]=val+1;
			visited[x+2][y-1]=true;
			qp.push({x+2,y-1});
		}
		if(y-2>=0 and x+1<n and (not visited[x+1][y-2])){
			chess[x+1][y-2]=val+1;
			visited[x+1][y-2]=true;
			qp.push({x+1,y-2});
		}
		if(x+2<n and y+1<n and (not visited[x+2][y+1])){
			chess[x+2][y+1]=val+1;
			visited[x+2][y+1]=true;
			qp.push({x+2,y+1});
		}
		if(y+2<n and x+1<n and (not visited[x+1][y+2])){
			chess[x+1][y+2]=val+1;
			visited[x+1][y+2]=true;
			qp.push({x+1,y+2});
		}
	}
	find_ways_knight(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<chess[i][j]<<" ";
		}
		cout<<endl;
	}
	// generateTrees(n);
}