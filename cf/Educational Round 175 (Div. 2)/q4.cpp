#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;
#define ll long long
#define pb push_back


//---- Debugger ---- //
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
ll binpow(ll b,ll p,ll mod){ll ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
//----------------- //



#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void processTestCase() {
    int n;
    cin >> n;
    vector<int> p(n + 1), d(n + 1, 0);
    for (int i = 2; i <= n; ++i) cin >> p[i];

    int max_d = 0;
    for (int i = 2; i <= n; ++i) {
        d[i] = d[p[i]] + 1;
        max_d = max(max_d, d[i]);
    }

    vector<vector<int>> dgrp(max_d + 1);
    dgrp[0].push_back(1);
    for (int i = 2; i <= n; ++i) dgrp[d[i]].push_back(i);

    vector<long long> dp(n + 1, 0), sum_d(max_d + 1, 0);
    dp[1] = sum_d[0] = 1;

    for (int d = 1; d <= max_d; ++d) {
        if (dgrp[d].empty()) continue;
        if (d == 1) {
            sum_d[d] = dgrp[d].size() % MOD;
            for (int v : dgrp[d]) dp[v] = 1;
        } else {
            long long sum_prev = sum_d[d - 1], sum = 0;
            for (int v : dgrp[d]) {
                dp[v] = (sum_prev - dp[p[v]] + MOD) % MOD;
                sum = (sum + dp[v]) % MOD;
            }
            sum_d[d] = sum;
        }
    }

    cout << accumulate(sum_d.begin(), sum_d.end(), 0LL) % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) processTestCase();
    
    return 0;
}
