#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1]={0};
    int k;
    for(int i=0;i<n-1;i++){
        cin>>k;
        a[k]+=1;
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            cout<<i<<endl;
            break;
        }
    }

}