#include<iostream>
using namespace std;

void solve(int tc){
    long int row;
    long int col;
    cin>>row>>col;
    if(row==1 && col==1){
        cout<<"1";
        return;
    }
    if(row>col){
    if(row%2==1){
        long int ans=row-1;
        long long int cell=ans*ans+1;
        cell+=(col-1);
        cout<<cell;
        return;
    }
    else{
        long int ans=row;
        long long int cell=ans*ans;
        cell-=(col-1);
        cout<<cell;
        return;
    }
    }
    else{
    if(col%2==1){
        long int ans=col;
        long long int cell=ans*ans;
        cell-=(row-1);
        cout<<cell;
        return;
    }
    else{
        long int ans=col-1;
        long long int cell=ans*ans+1;
        cell+=(row-1);
        cout<<cell;
        return;
    }
    }
cout<<"-1";
        return;
}




int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve(i);
        cout<<"\n";
    }
}