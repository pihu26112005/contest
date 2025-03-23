#include <bits/stdc++.h>
using namespace std;

long long findMax(long long target) {
    if (target <= 0) return 0;
    long long count = 2;
    while ((count * (count - 1)) / 2 <= target) {
        count++;
    }
    return count - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        long long sumT;
        cin >> sumT;
        vector<long long> l;

        if (sumT == 0) {
            cout << "0\n";
            continue;
        }

        while (sumT > 0) {
            long long max_level = findMax(sumT);
            l.push_back(max_level);
            sumT -= (max_level * (max_level - 1)) / 2;
        }
        long long top = accumulate(l.begin(), l.end(), 0LL);
        cout << top << "\n";

        long long y_position = 1;
        for (size_t index = 0; index < l.size(); ++index) {
            long long level_size = l[index];
            for (long long step = 0; step < level_size; ++step) {
                cout << (index + 1) << " " << y_position << "\n";
                y_position++;
            }
        }
    }

    return 0;
}
