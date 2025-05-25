// const int MOD = 1e9 + 7;

// class Solution {
// public:
//     // only giving lca for more than 2 child tree
//     pair<int, int> lca(int n1, int n2, unordered_map<int, vector<int>>& m,
//                        int root) {
//         if (root == n1 || root == n2) {
//             return {root, 1};
//         }
//         int count = 0;
//         int found_node = -1;
//         for (int child : m[root]) {
//             auto res = lca(n1, n2, m, child);
//             if (res.first != -1) {
//                 count ++;
//                 if (found_node == -1) {
//                     found_node = res.first;
//                 }
//             }
//         }
//         if (count == 0) {
//             return {-1, 0}; // none found
//         }
//         if (count == 1) {
//             return {found_node, 1}; // one found
//         }
//         return {root, count}; // both found, this is the LCA
//     }

//     int level(unordered_map<int, int> p, int root, int n) {
//         int ans = 0;
//         while (n != root) {
//             ans++;
//             n = p[n];
//         }
//         return ans;
//     }

//     vector<int> assignEdgeWeights(vector<vector<int>>& edges,
//                                   vector<vector<int>>& q) {
//         vector<int> ans;
//         unordered_map<int, vector<int>> m;
//         unordered_map<int, int> p;
//         for (auto i : edges) {
//             m[i[0]].push_back(i[1]);
//             p[i[1]] = i[0];
//         }
//         for (auto i : q) {
//             pair<int, int> pr = lca(i[0], i[1], m, 1);
//             int l = pr.first;
//             int h1 = level(p, 1, i[0]);
//             int h2 = level(p, 1, i[1]);
//             int h3 = level(p, 1, l);
//             int lvl = h1 + h2 - 2 * h3;
//             int result = lvl == 0 ? 0 : 1;
//             for (int i = 0; i < lvl - 1; i++) {
//                 result = (result * 2) % MOD;
//             }
//             ans.push_back(result);
//         }
//         return ans;
//     }
// };

                                                    // till --> lca = o(n) tc = o(n*q)
                                                    // with binary lifitn lca = o(logn) tc = o(q*logn)



#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int LOG = 20;  // up to ~10^6 nodes (since 2^20 > 10^6)

class Solution {
public:
    vector<vector<int>> up;
    vector<int> depth;

    void dfs(int node, int parent, unordered_map<int, vector<int>>& m) {
        up[node][0] = parent;
        for (int j = 1; j < LOG; ++j) {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }
        for (int child : m[node]) {
            if (child != parent) {
                depth[child] = depth[node] + 1;
                dfs(child, node, m);
            }
        }
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int j = LOG - 1; j >= 0; --j) {
            if (depth[u] - (1 << j) >= depth[v]) // (1 << j) = 2^j
                u = up[u][j];
        }
        if (u == v) return u;
        for (int j = LOG - 1; j >= 0; --j) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& q) {
        int n = edges.size() + 1;  // number of nodes
        unordered_map<int, vector<int>> m;
        for (auto& edge : edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);  // treat as undirected
        }

        up.assign(n + 1, vector<int>(LOG));
        depth.assign(n + 1, 0);

        int root = 1;
        dfs(root, root, m);

        vector<int> ans;
        for (auto& query : q) {
            int u = query[0];
            int v = query[1];
            int ancestor = get_lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[ancestor];

            int result = dist == 0 ? 0 : 1;
            for (int i = 0; i < dist - 1; ++i) {
                result = (result * 2) % MOD;
            }
            ans.push_back(result);
        }
        return ans;
    }
};


// up[node][j] → the 2^j-th ancestor of node.
// Examples:
// up[4][0] → the 1st parent (direct parent).
// up[4][1] → the 2nd ancestor (parent’s parent).
// up[4][2] → the 4th ancestor.
// up[4][3] → the 8th ancestor, etc.

// up[node][j] = up[up[node][j - 1]][j - 1];
// To jump 2^j steps up,
// split it as two jumps of size 2^{j-1}.
// and so 2^{j-1} + 2^{j-1}. = 2^j