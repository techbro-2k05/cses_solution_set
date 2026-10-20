#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[20][10][2][2];

ll solve(string &num, int pos, int prev, int tight, int leading_zero) {
    if (pos == num.size()) return 1;

    if (dp[pos][prev][tight][leading_zero] != -1)
        return dp[pos][prev][tight][leading_zero];

    ll res = 0;
    int limit = tight ? (num[pos] - '0') : 9;

    for (int d = 0; d <= limit; d++) {
        int new_tight = (tight && (d == limit));
        int new_leading = (leading_zero && d == 0);

        // skip if adjacent digits same (except leading zeros)
        if (!new_leading && d == prev) continue;

        res += solve(num, pos + 1, d, new_tight, new_leading);
    }

    return dp[pos][prev][tight][leading_zero] = res;
}

ll f(ll x) {
    string num = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solve(num, 0, 0, 1, 1);
}

int main() {
    ll a, b;
    cin >> a >> b;

    cout << f(b) - f(a - 1) << endl;
}