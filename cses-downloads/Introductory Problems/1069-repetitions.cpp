#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int s_len=s.length();
    int count=1;
    int max_count=0;
    if(s_len==1){
        max_count=1;
    }
    for(int i=1;i<s_len;i++){
        if(s[i]==s[i-1]){
            count+=1;
            
        }
        else{
            count=1;
        }
        max_count=count>max_count?count:max_count;
    }
    // if(max_count==1){
    //     max_count=0;
    // }
    cout<<max_count;


}