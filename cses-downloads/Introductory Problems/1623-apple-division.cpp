#include <bits/stdc++.h>
using namespace std;
const int N =2e5+2;
int arr[N]={0};
// int n;
long int m;
// int index=0;
vector<long int> my_array;
bool visited[N];
vector<long int>my_answer;
long long int dp[2][N]; 
vector<int> arrs;
int times=0;
vector<long int> check_prime(long int n){
    int upper=sqrt(n);
    int div_count=0;
    vector<long int> num;
    for(int i=1;i<=upper;i++){
        if(n/i<i){
            break;
        }
        if(n%i==0){
            if(n/i==i){
                num.push_back(i);
                break;
            }
            else{
                num.push_back(n/i);
                num.push_back(i);
            }
        }
    }
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    return num;
}

long int find_min_diff(long int a,long int b){
    if(a>=b){
        return (a/b)*b;
    }
    else{
        vector <long int> ll=check_prime(b);
        int curr_diff=b-a;
        int curr_num=b;
        for(int i=0;i<ll.size();i++){
            int diff=abs(ll[i]-a);
            if(diff<curr_diff){
                curr_diff=diff;
                curr_num=ll[i];
            }
            else{
                break;
            }
        }
        return curr_num;
    }
}

bool check_sorted(vector<int> &arr,int n){
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            return false;
        }
    }
    return true;
}

long long diff=1e9;
vector<long long> apples;
// long long 
void brute_force_app(int index, int n, long long group1, long long group2){
    if(index==n){
        diff=min(diff,abs(group1-group2));
        return;
    }
    brute_force_app(index+1,n,group1+apples[index],group2);
    brute_force_app(index+1,n,group1,group2+apples[index]);
}

void solve(){
    int n; 
    cin>>n; 
    apples.resize(n);
    for(int i=0;i<n;i++){
        cin>>apples[i];
    }
    if(n==1){
        cout<<apples[0]<<endl;
        return;
    }
    sort(apples.begin(),apples.end());
    brute_force_app(0,n,(long long)0,(long long)0);
    cout<<diff<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}