// wrong 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int S = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            S |= (1 << i);
        }
    }

    vector<int> cnt(1 << n, 0);
    for (const string& str : s) {
        int mask = 0;
        for (char c : str) {
            int bit = c - 'A';
            mask |= (1 << bit);
        }
        cnt[mask]++;
    }

    int total_sum = 0;
    for (int ai : a) {
        total_sum += ai;
    }
    vector<int> sum_mask(1 << n, 0);
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum_mask[mask] += a[i];
            }
        }
    }
    vector<int> not_sum(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
        not_sum[mask] = total_sum - sum_mask[mask];
    }

    vector<long long> F(1 << n, 0);
    for (int mask = 0; mask < (1 << n); mask++) {
        F[mask] = cnt[mask];
    }
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << i)) {
                F[mask] += F[mask ^ (1 << i)];
            }
        }
    }

    vector<long long> ans(total_sum + 1, 0);

    for (int a_mask = 0; a_mask < (1 << n); a_mask++) {
        if (cnt[a_mask] == 0) continue;
        int X = a_mask & S;
        int complement_X = ((1 << n) - 1) ^ X;
        long long compatible = F[complement_X];
        if ((a_mask & X) == 0) {
            compatible -= cnt[a_mask];
        }
        int a_rest = a_mask & (~S);
        int a_s = a_mask & S;
        for (int s_part = 0; s_part < (1 << __builtin_popcount(S)); s_part++) {
            int b_s = 0;
            int temp = s_part;
            int pos = 0;
            for (int i = 0; i < n; i++) {
                if (S & (1 << i)) {
                    if (temp & 1) {
                        b_s |= (1 << i);
                    }
                    temp >>= 1;
                    pos++;
                }
            }
            if ((a_s & b_s) != 0) continue;
            if (b_s & X) continue;
            int full_s = a_s | b_s;
            int b_mask_rest = 0;
            for (int rest_part = 0; rest_part < (1 << (n - __builtin_popcount(S))); rest_part++) {
                int b_rest = 0;
                temp = rest_part;
                pos = 0;
                for (int i = 0; i < n; i++) {
                    if (!(S & (1 << i))) {
                        if (temp & 1) {
                            b_rest |= (1 << i);
                        }
                        temp >>= 1;
                        pos++;
                    }
                }
                int b_mask = b_s | b_rest;
                int union_mask = a_mask | b_mask;
                int k = not_sum[union_mask];
                ans[k] += 1LL * cnt[a_mask] * cnt[b_mask];
            }
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        if (cnt[mask] < 2) continue;
        if ((mask & S) != 0) continue;
        int k = not_sum[mask];
        long long pairs = 1LL * cnt[mask] * (cnt[mask] - 1) / 2;
        ans[k] += pairs;
    }

    for (int k = 0; k <= total_sum; k++) {
        cout << ans[k] << ' ';
    }
    cout << '\n';

    return 0;
}