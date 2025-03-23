#include <iostream>
#include <vector>
using namespace std;

int findbitm(unsigned int num) {
    if (num < 2) return 0;
    unsigned int prev = num - 1;
    int h = 31 - __builtin_clz(prev);
    return (num == (1u << h)) ? ((1u << h) - 1) : ((1u << (h + 1)) - 1);
}

void pt() {
    int len;
    unsigned int val;
    cin >> len >> val;

    int maxCount = 0;
    for (int count = 0; count <= len; count++) {
        unsigned int mask = (count == 0) ? 0 : findbitm(count);
        if ((mask & (~val)) == 0) {
            int needed = (mask == val) ? count : count + 1;
            if (needed <= len) maxCount = count;
        }
    }

    vector<unsigned int> o;
    if (maxCount == 0) {
        o.push_back(val);
    } else {
        for (int i = 0; i < maxCount; i++) {
            o.push_back(i);
        }
        unsigned int mask = findbitm(maxCount);
        if (mask != val) o.push_back(val & (~mask));
    }

    while (o.size() < static_cast<size_t>(len)) {
        o.push_back(maxCount > 0 ? 0u : val);
    }

    for (auto num : o) cout << num << " ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) pt();
    return 0;
}