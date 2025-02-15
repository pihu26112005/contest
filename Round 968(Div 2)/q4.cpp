#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long compute_sum_f(int m, int max_v) {
    if (m <= max_v) {
        // Sum of series (v+1) * (m+1)
        return (long long)(m + 1) * (max_v + 1);
    } else {
        // Sum f(0) to f(max_v) + sum f(max_v+1) to f(m)
        long long sum1 = (long long)(max_v + 1) * (max_v + 1);
        long long sum2 = (long long)(m + 1) * m / 2 - (long long)max_v * (max_v + 1) / 2;
        return sum1 + sum2;
    }
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<set<int>> unique_elements(n);

        int max_v = 0;
        for (int i = 0; i < n; ++i) {
            int l;
            cin >> l;
            for (int j = 0; j < l; ++j) {
                int a;
                cin >> a;
                unique_elements[i].insert(a);
            }
            
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
