#include<bits/stdc++.h>
using namespace std; 
vector<string>chess;

bool check(int row,int col,int n){
	// if queen in same row
	for(int i=0;i<n;i++){
		if(chess[row][i]=='Q'){
			return false;
		}
	}
	//if queen in same col
	for(int i=0;i<n;i++){
		if(chess[i][col]=='Q'){
			return false;
		}
	}
	//if queen in first diagonal
	int p_row=row-1,p_col=col-1; 
	while(p_row>=0 and p_col>=0){
		if(chess[p_row][p_col]=='Q'){
			return false;
		}
		p_col--;
		p_row--;
	}
	p_row=row+1;
	p_col=col+1;
	while(p_row<n and p_col<n){
		if(chess[p_row][p_col]=='Q'){
			return false;
		}
		p_col++;
		p_row++;
	}

	// in second diagonal 
	p_row=row+1;
	p_col=col-1;
	while(p_row<n and p_col>=0){
		if(chess[p_row][p_col]=='Q'){
			return false;
		}
		p_col--;
		p_row++;
	}
	p_row=row-1;
	p_col=col+1;
	while(p_row>=0 and p_col<n){
		if(chess[p_row][p_col]=='Q'){
			return false;
		}
		p_col++;
		p_row--;
	}
	return true;
}
vector<vector<string>>final_config; 
int answer=0;
void build_chess_board(int row,int n){
	if(row>=n){
		answer+=1;
		return;
	}
	for(int col=0;col<n;col++){
		if(check(row,col,n) and chess[row][col]=='.'){
			chess[row][col]='Q';
			build_chess_board(row+1,n);
			chess[row][col]='.';
		}
	}
}


void solveNQueens(int n) {
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		chess.push_back(s);
	}
    build_chess_board(0,n);
}

int main(){
	int n=8; 
	solveNQueens(n);
	cout<<answer<<endl;
	// generateTrees(n);
}