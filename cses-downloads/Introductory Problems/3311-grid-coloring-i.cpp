#include<bits/stdc++.h>
using namespace std; 
vector<string>chess;
bool ans=false;
int mods=1e9+7;
int n,m; 
vector<char>colors={'A','B','C','D'};
bool check(int row,int col,char val){
	if(row>0 and chess[row-1][col]==val){
		return false;
	}
	if(col>0 and chess[row][col-1]==val){
		return false;
	}
	return true;
}
void color_it(int row,int col){
	if(col==m){
		row++;
		col=0;
	}
	if(row==n){
		if(ans==false){
			ans=true; 
		}
		return;
	}
	int x=chess[row][col];
	for(auto i: colors){
		if(i==chess[row][col]){
			continue;
		}
		if(check(row,col,i)){
			chess[row][col]=i; 
			color_it(row,col+1);
			if(ans){
				return;
			}
			chess[row][col]=x;
		}
	}

}

int main(){
	ans=false;
	cin>>n>>m;  
	chess.resize(n); 
	for(int i=0;i<n;i++){
		cin>>chess[i];
	}
	color_it(0,0);
	if(not ans){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	for(int i=0;i<n;i++){
		cout<<chess[i]<<endl;
	}
	// generateTrees(n);
}