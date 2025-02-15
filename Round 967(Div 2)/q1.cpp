#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinOperations(vector<int>& a, int n) {
    int ans = 0;
    sort(a.begin(), a.end());
    // finding maximum constant subarray
    int maxCount = 1, count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            count++;
        } else {
            maxCount = max(maxCount, count);
            count = 1;
        }
    }
    maxCount = max(maxCount, count);
    ans = n - maxCount;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << findMinOperations(a, n) << endl;
    }
    return 0;
}
