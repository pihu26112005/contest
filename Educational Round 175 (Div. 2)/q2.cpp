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



ll findZeroCrossings(const string& s, ll n) {
    vector<ll> pos(n + 1, 0);
    ll curr = 0;
    
    for (ll i = 0; i < n; ++i) {
        curr += (s[i] == 'R') ? 1 : -1;
        pos[i + 1] = curr;
    }

    for (ll t = 1; t <= n; ++t) {
        if (pos[t] == 0) return t;
    }
    return -1;
}

void processTestCase() {
    ll n, x, k;
    string s;
    cin >> n >> x >> k >> s;
    
    ll count = 0, time = 0;
    bool tillz = false;

    for (ll i = 0; i < n && time < k; ++i) {
        x += (s[i] == 'R') ? 1 : -1;
        time++;
        if (x == 0) {
            count++;
            tillz = true;
            break;
        }
    }

    if (!tillz && x == 0) {
        count++;
        time = n;
    }

    ll rt = k - time;
    if (rt > 0 && (tillz || x == 0)) {
        ll ctime = findZeroCrossings(s, n);
        if (ctime != -1) {
            count += rt / ctime;
            rt %= ctime;
        } else {
            ll cdel = accumulate(s.begin(), s.end(), 0, [](ll sum, char c) {
                return sum + (c == 'R' ? 1 : -1);
            });

            if (cdel == 0) {
                count += rt / n;
                rt %= n;
                for (ll i = 1; i <= rt; ++i) {
                    if (findZeroCrossings(s.substr(0, i), i) != -1) {
                        count++;
                        break;
                    }
                }
            } else {
                for (ll i = 1; i <= min(rt, n); ++i) {
                    if (findZeroCrossings(s.substr(0, i), i) != -1) {
                        count++;
                        break;
                    }
                }
            }
        }
    }

    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) processTestCase();
    return 0;
}
