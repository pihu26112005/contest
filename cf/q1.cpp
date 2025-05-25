#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
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


constexpr int MODULO = 1e9 + 7;

ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

vector<int> k, kin;

void cfm(int limit) {
    k.assign(limit + 1, 1);
    kin.assign(limit + 1, 1);
    
    for (int i = 2; i <= limit; ++i) {
        k[i] = (1LL * k[i - 1] * i) % MODULO;
    }
    
    kin[limit] = mod_pow(k[limit], MODULO - 2, MODULO);
    for (int i = limit - 1; i >= 0; --i) {
        kin[i] = (1LL * kin[i + 1] * (i + 1)) % MODULO;
    }
}

int foecc(int n, int r) {
    if (n < r || r < 0) return 0;
    return (1LL * k[n] * kin[r] % MODULO * kin[n - r]) % MODULO;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int max_val = 0;

    for (int &num : arr) {
        cin >> num;
        max_val |= num;
    }

    vector<int> o(max_val + 1, 0);
    for (int num : arr) {
        o[num]++;
    }

    vector<int> cntitave(max_val + 1, 0);
    copy(o.begin(), o.end(), cntitave.begin());

    for (int bit = 0; bit < 20; ++bit) {
        for (int x = 0; x <= max_val; ++x) {
            if (x & (1 << bit)) {
                cntitave[x] += cntitave[x ^ (1 << bit)];
            }
        }
    }

    cfm(max(n, max_val));

    vector<int> cs(max_val + 1, 0);
    for (int x = 0; x <= max_val; ++x) {
        cs[x] = foecc(cntitave[x], k);
    }

    vector<int> final_result = cs;

    for (int bit = 0; bit < 20; ++bit) {
        for (int x = 0; x <= max_val; ++x) {
            if (x & (1 << bit)) {
                final_result[x] = (final_result[x] - final_result[x ^ (1 << bit)] + MODULO) % MODULO;
            }
        }
    }

    int queries;
    cin >> queries;
    while (queries--) {
        int query_val;
        cin >> query_val;
        cout << (query_val > max_val ? 0 : final_result[query_val]) << '\n';
    }

    return 0;
}
