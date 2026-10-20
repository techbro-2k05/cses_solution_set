#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// __gcd(n,m)
#define indexed_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define N 1000005
// int visited[N][N]={0};
const int mods_1= 1e9+7;
const int mods_2=998244353;//use this for string hashing
// vector<int>graph[N];

// #define my_str a
// long long check_it[N];


//for syntax
#define f(start,end) for(int i=start;i<end;i++)
#define fullf(start,end) for(int i=start;i<=end;i++)
#define f0(end) f(0,end)
#define f1(end) f(1,end)
#define fneg(end) for(int i=end;i>=0;i--)


//binary operations on 64 bits long long integer
#define bincount_leading_zero(x) __builtin_clzll(x)
#define bincount_trailing_zero(x) __builtin_ctzll(x)
#define bin_one_count(x) __builtin_popcountll(x)
#define bin_one_even_odd(x) __builtin_parityll(x)



//vector and map operations
#define pf push_front
#define pb push_back
#define ff first
#define ss second
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()


//for usual cf outputs
#define yes cout << "YES" << nl
#define no cout << "NO" << nl

//data-types
#define ll long long 
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p32>> vvp32;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;

//O(1)
#define pb push_back
#define emb emplace_back
#define emf emplace_front
#define po pop_back
#define pf push_front
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define make_unique(x) \
    sort(all(x));      \
    (x).resize(unique(all(x)) - (x).begin());
//unique -> only starting elements unique followed by duplicates, not in sorted order(preserves og order)
#define print_vec(v)             \
    for(auto x: v) cout << x << " "; \
    cout << "\n"
#define minify(x, y) x = min(x, y) //same data type to be followed
#define maxify(x, y) x = max(x, y) //same data type to be followed
bool check_sorted_inc(vector<long long int>&a){
    for(int i=1;i<a.size();i++){
        if(a[i]<=a[i-1]){
            return false;
        }
    }
    return true;
}
bool check_sorted_dec(vector<long long int>&a){
    for(int i=1;i<a.size();i++){
        if(a[i]>=a[i-1]){
            return false;
        }
    }
    return true;
}
// O(log(N))-> binary exponentation
long long power(long long A, long long B)
{
    if (B == 0)
        return 1;

    long long res = power(A, B / 2);

    if (B % 2)
        return res * res * A;
    else
        return res * res;
}
// O(log(N))
v64 primeFactors(ll x, const v64 &spf)
{
    v64 factors;
    while (x != 1)
    {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}
vector<char> segmentedSieveNoPreGen(long long L, long long R) {
    vector<char> isPrime(R - L + 1, true);
    long long lim = sqrt(R);
    for (long long i = 2; i <= lim; ++i)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
//o(N)
void linearSieve(ll n, v64 &primes, v64 &spf)
{
    vector<bool> isprime(n + 1, true); // true means the number is prime
    spf.resize(n + 1);                 // Smallest prime factor (SPF)
    isprime[0] = isprime[1] = false;   // 0 and 1 are not prime
 
    for (ll i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i); // i is prime
            spf[i] = i;          // Smallest prime factor of a prime is itself
        }
 
        // Mark multiples of i
        for (ll p : primes)
        {
            if (i * p > n)
                break;
            isprime[i * p] = false; // i * p is not prime
            spf[i * p] = p;         // Smallest prime factor of i * p
            if (i % p == 0)
                break;
        }
    }
}

#define PII pair<int, int>

string decToBinary(ll n) {
    string bin = "";
    
    while (n > 0ll) {
        int bit = n%2ll;
        bin.push_back('0' + bit);
        n /= 2ll;
    }
  
    reverse(bin.begin(), bin.end());
    return bin;
}

// const int mods=1000000007;
// #define PII2 pair<long long int, long long int>

int gcdExtended(int a, int b, int &x, int &y) {
    // Base Case 
    if (a == 0)  { 
        x = 0; 
        y = 1; 
        return b; 
    } 

    int x1, y1; 
    int gcd = gcdExtended(b%a, a, x1, y1); 

    // Update x and y using results of 
    // recursive call 
    x = y1 - (b/a) * x1; 
    y = x1; 
    return gcd; 
} 
int findGCD(int a, int b) {
    int x = 1, y = 1;
    return gcdExtended(a, b, x, y);
}
v64 primes,spf;
//for sorting in custom comparator 
bool comp(PII a, PII b)
{   double dist_1=a.second/(double)a.first;
        double dist_2=b.second/(double)b.first;
        return dist_1>dist_2;
}

//ordered set
template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


//inversion counts
long long int countInversions(vector<int>& a) {
    indexed_set<pair<int, int>> os;
    long long int inv_count = 0;
    int n = a.size();
    for (int i = n - 1; i >= 0; --i) {
        // Count elements strictly less than a[i], including duplicate handling with index
        inv_count += os.order_of_key({a[i], i});
        inv_count%=2;
        os.insert({a[i], i});
    }
    return inv_count;
}


/*think it out my boiiii







*/


// vector<int>mapitout(N+1,0);



vector<int> getdiv(int x,int k){
    vector<int>div;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            if(x==i*i){
                div.push_back(i);
            }
            else{
                div.push_back(i);
                div.push_back(x/i);
            }
        }
    }
    sort(all(div));
    return div;
}

#include <climits>
int power(int x, int y)
{
    if (y == 0)
        return 1;

    long long int temp = power(x, y / 2);
    temp%=mods_2;
    if (y % 2 == 0){
        temp*=temp;
        temp%=mods_2;
        return (int)temp;
    }
    else{
        temp*=temp;
        temp%=mods_2;
        temp*=x;
        temp%=mods_2;
        return temp;
    }
}
class Compare {
public:
    bool operator()(pair<int,long long int> below, pair<int,long long int> above)
    {
        return below.first>above.first;
    }
};

string simplifyPath(string A) {
    string curr; 
    vector<string>answer; 
    int n=A.length();
    for(int i=0;i<n;){
        if(A[i]=='/'){
            while(i<n and A[i]=='/'){
                i++;
            }
            curr.clear();
            while(i<n and A[i]!='/'){
                curr.push_back(A[i]);
                i++;
            }
            if(curr=="."){
                continue;
            }   
            else if(curr[0]=='.' and curr[1]=='.'){
                // cout<<"hello\n";
                if(not answer.empty()){
                    answer.pop_back();
                }
                // print_vec(answer);
            }
            else{
                answer.push_back(curr);
            }
        }
        else{
            i++;
        }
    }
    string fin; 
    fin.push_back('/');
    for(auto i:answer){
        fin+=i;
    }
    return fin;
}


void solve() {
    int n,a,b; 
    cin>>n>>a>>b; 
    bool s=false;
    if(a>b){
        swap(a,b);
        s=true;
    }
    if(n<a+b){
        no;
        return;
    }
    if(a==b and b==0){
        yes;
        f(1,n+1){
            cout<<i<<" ";
        }
        cout<<endl;
        f(1,n+1){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    if(b>=1){
        if(a==0){
            no;
            return;
        }
    }
    vector<int>vp(n); 
    int p=1;
    bool opened=false;
    f0(n){
        if(a>b){
            vp[i]=p;
            opened=false;
            a--;
        }
        else{
            if(b==0){
                vp[i]=i+1; 
            }
            else{
                if(not opened){
                    opened=true;
                    p=i+1;
                }
                vp[i]=i+2;
                b-=1;
            }
        }
    }
    yes;
    if(not s){
        f0(n){
            cout<<i+1<<" ";
        }
        cout<<endl;
        print_vec(vp);
    }
    else{
        print_vec(vp);
        f0(n){
            cout<<i+1<<" ";
        }
        cout<<endl;
    
    }
}





int main() {
    fast_cin();
    int t=1;
    t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}