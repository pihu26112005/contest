#include <iostream>
using namespace std;

void solve() {
    int length, value;
    cin >> length >> value;

    if (length == 1) {
        cout << value << "\n";
        return;
    }

    int limit = length - 1;
    for (int idx = 0; idx < length; ++idx) {
        if (idx == 0 || idx == length - 1) {
            cout << value << " ";
        } else {
            int pos = idx;
            cout << ((pos & limit) == pos ? value : 0) << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}
