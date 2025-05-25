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



// vector<int> adj[100005]; // Adjacency list for the tree
// int dist[100005];        // Distance from each vertex to en

// void bfs(int en, int n) {
//     queue<int> q;
//     vector<bool> visited(n + 1, false);
//     q.push(en);
//     visited[en] = true;
//     dist[en] = 0;
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         for (int v : adj[u]) {
//             if (!visited[v]) {
//                 visited[v] = true;
//                 dist[v] = dist[u] + 1;
//                 q.push(v);
//             }
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t; 
//     while (t--) {
//         int n, st, en;
//         cin >> n >> st >> en;
//         for (int i = 1; i <= n; ++i) {
//             adj[i].clear();
//         }
//         for (int i = 0; i < n - 1; ++i) {
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         bfs(en, n);
//         vector<pair<int, int>> vertices;
//         for (int i = 1; i <= n; ++i) {
//             vertices.push_back({dist[i], i});
//         }
//         sort(vertices.rbegin(), vertices.rend());
//         for (int i = 0; i < n; ++i) {
//             cout << vertices[i].second;
//             if (i < n - 1) cout << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }