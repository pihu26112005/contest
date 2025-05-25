#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
#include <iostream>
using namespace std;
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


 
bool sq(ll x) {
    ll s = sqrt(x);
    return s * s == x;
}
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         ll totalSum = (1LL * n * (n + 1)) / 2;
//         if (sq(totalSum)) {
//             cout << "-1\n";
//             continue;
//         }
//         set<int, greater<int>> kitnahau;
//         for (int i = 1; i <= n; i++) {
//             kitnahau.insert(i);
//         }
//         vector<int> p;
//         ll sum = 0;
//         while (!kitnahau.empty()) {
//             for (auto it = kitnahau.begin(); it != kitnahau.end(); ++it) {
//                 if (!sq(sum + *it)) {
//                     sum += *it;
//                     p.push_back(*it);
//                     kitnahau.erase(it);
//                     break;
//                 }
//             }
//         }
//         for (int num : p) {
//             cout << num << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }


int main() {
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        long long s = (1LL * n * (n+1))/2;
        if(sq(s)) 
        {
            cout<<-1<<endl;
            continue;
        }
        unordered_map<int,bool> mp;
        ll ss = 0;
        for(int i=1;i<=n;i++){
            // ss+=i;
            if(sq(ss+i)){
                // ss+=i;
                mp[i] = true;
            }
            else{
                ss+=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(!mp[i]){
                cout<<i<<" ";
            }
        }
        vector<int> v;
        for(auto it:mp){
            if(it.second){
                v.push_back(it.first);
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}