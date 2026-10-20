#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
// __gcd(n,m)
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define N 1005
int visited[N][N]={0};
const int inf= 1e9+7;
vector<int>graph[N];
long long dp[N];
// #define my_str a
long long check_it[N];
#define f(start,end) for(int i=start;i<=end;i++)
#define f0(end) for(int i=0;i<end;i++)
#define f1(end) for(int i=1;i<end;i++) 
#define fneg(end) for(int i=end;i>=0;i--)
#define bincount_leading_zero(x) __builtin_clz(x)
#define bincount_trailing_zero(x) __builtin_ctz(x)
#define bin_one_count(x) __builtin_popcount(x)
#define bin_one_even_odd(x) __builtin_parity(x)
#define pf push_front
#define pb push_back
#define ff first
#define ss second
// #define mp make_pair
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
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
// O(N)
#define pb push_back
#define po pop_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define make_unique(x) \
    sort(all(x));      \
    (x).resize(unique(all(x)) - (x).begin());
#define print_vec(v)             \
    for(auto x: v) cout << x << " "; \
    cout << "\n"
#define minify(x, y) x = min(x, y)
#define maxify(x, y) x = max(x, y)

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
            primes.push_back(i); // `i` is prime
            spf[i] = i;          // Smallest prime factor of a prime is itself
        }
 
        // Mark multiples of `i`
        for (ll p : primes)
        {
            if (i * p > n)
                break;
            isprime[i * p] = false; // `i * p` is not prime
            spf[i * p] = p;         // Smallest prime factor of `i * p`
            if (i % p == 0)
                break;
        }
    }
}



void outputs(int val){
    cout<<(val==1?"Yes":"No")<<endl;
    return;
}
v64 primes,spf;
int changed_occ=0;

set<long long>squares; 
// void recurse_set(int value, int start,int end){
//     int mid=(start+end)/2; 
//     dp[mid]=value;
//     recurse_set()

// }
#define PII pair<int, int>
class Compare {
public:
    bool operator()(PII below, PII above)
    {
        if (below.second-below.first < above.second-above.first) {
            return true;
        }
        else if (below.second-below.first == above.second-above.first
                 && below.first > above.first) {
            return true;
        }

        return false;
    }
};
string decToBinary(int n) {
    string bin = "";
    
    while (n > 0) {
        int bit = n%2;
          bin.push_back('0' + bit);
        n /= 2;
    }
  
    reverse(bin.begin(), bin.end());
    return bin;
}
vector<long int>a;
void solve(){
    int n;
    long int m;
    cin>>n>>m; 
    a.resize(n); 
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int start=0;
    int end=0; 
    vector<long int>pref(n,a[0]); 
    for(int i=1;i<n;i++){
        pref[i]=pref[i-1]+a[i];
    }
    long long curr_sum=0;
    int count_occ=0;
    for(int i=0;i<n;i++){
        end=i; 
        curr_sum+=a[end];
        if(curr_sum>m){
            while(curr_sum>m and start<=end){
                curr_sum-=a[start];
                start+=1; 
            }
        }
        if(curr_sum==m){
            count_occ++;
            curr_sum-=a[start];
            start+=1 ;
        }
    }
    cout<<count_occ<<endl;
}


int main() {
    // linearSieve(floor(pow(sqrt(10), 9)), primes, spf);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // int n=1000000;
    // cin>>t;
    while(t--){
        solve();
    }
}