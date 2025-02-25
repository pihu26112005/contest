#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define LOOP(i, n) for (int i = 0; i < (n); ++i)
#define READ_INT(x) cin >> x
#define PRINT_RESULT(vec) for (auto v : vec) cout << v << " "; cout << "\n";

#define HIGHEST_BIT_POS(x) (31 - __builtin_clz(x))

unsigned int generateBitmask(unsigned int num) {
    if (num < 2) return 0;
    unsigned int prev = num - 1;
    int highBit = HIGHEST_BIT_POS(prev);
    return (num == (1u << highBit)) ? ((1u << highBit) - 1) : ((1u << (highBit + 1)) - 1);
}

void handleTestCase() {
    int arrSize;
    unsigned int targetVal;
    READ_INT(arrSize);
    READ_INT(targetVal);

    int optimal = 0;
    for (int cur = 0; cur <= arrSize; ++cur) {
        unsigned int bitmask = (cur == 0) ? 0 : generateBitmask(cur);
        if ((bitmask & (~targetVal)) == 0) {
            int needed = (bitmask == targetVal) ? cur : cur + 1;
            if (needed <= arrSize) optimal = cur;
        }
    }

    vector<unsigned int> results;
    if (optimal == 0) {
        results.push_back(targetVal);
    } else {
        LOOP(i, optimal) results.push_back(i);
        unsigned int bitmask = generateBitmask(optimal);
        if (bitmask != targetVal) results.push_back(targetVal & (~bitmask));
    }

    while (results.size() < static_cast<size_t>(arrSize)) {
        results.push_back(optimal > 0 ? 0u : targetVal);
    }

    PRINT_RESULT(results);
}

int main() {
    FAST_IO;
    int t;
    READ_INT(t);
    while (t--) handleTestCase();
    return 0;
}
