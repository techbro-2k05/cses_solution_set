#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    cin>>a[0];
    if(n==1){
        cout<<"0";
    }
    else{
    long long int ans=0;
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            ans+=(a[i-1]-a[i]);
            a[i]=a[i-1];
        }
    }
    cout<<ans;}
}