#include <bits/stdc++.h>
using namespace std;

#define int long long

// Function to compute the longest unique subarray
pair<int, int> getMaxUniqueSegment(const vector<int>& arr) {
    unordered_map<int, int> countMap;
    for (int num : arr) {
        countMap[num]++;
    }

    int start = 0, end = 0, bestStart = -1, bestEnd = -1;
    
    while (end < arr.size()) {
        if (countMap[arr[end]] == 1) {
            end++;
        } else {
            if ((end - start) > (bestEnd - bestStart)) {
                bestStart = start;
                bestEnd = end - 1;
            }
            start = end + 1;
            end = start;
        }
    }

    if ((end - start) > (bestEnd - bestStart)) {
        bestStart = start;
        bestEnd = end - 1;
    }

    return (bestStart > bestEnd) ? pair<int, int>(-1, -1) : pair<int, int>(bestStart + 1, bestEnd + 1);
}

void processTestCases() {
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        pair<int, int> result = getMaxUniqueSegment(arr);
        
        if (result.first == -1 && result.second == -1) {
            cout << 0 << endl;
            continue;
        } else {
            cout << result.first << " " << result.second << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    processTestCases();
    return 0;
}