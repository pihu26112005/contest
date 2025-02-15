#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Function to generate unique subsequences of a given size
void generateSubsequences(vector<int>& a, int index, vector<int>& current, set<vector<int>>& subsequences, unordered_set<int>& used, int size) {
    if (current.size() == size) {
        subsequences.insert(current);
        return;
    }
    
    // Base case: if we've reached the end of the array, return
    if (index == a.size() || current.size() > size) {
        return;
    }

    // Exclude the current element
    generateSubsequences(a, index + 1, current, subsequences, used, size);

    // Include the current element only if it hasn't been used in the current subsequence
    if (used.find(a[index]) == used.end()) {
        current.push_back(a[index]);
        used.insert(a[index]);

        generateSubsequences(a, index + 1, current, subsequences, used, size);

        // Backtrack: remove the last element added and mark it as unused
        used.erase(a[index]);
        current.pop_back();
    }
}

// Function to solve the problem
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> seen;
    vector<int> result;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (seen.find(a[i]) == seen.end()) {
            seen.insert(a[i]);
            result.push_back(a[i]);
        }
    }

    int size = result.size();
    cout << size << endl;
    set<vector<int>> subsequences;
    vector<int> current;
    unordered_set<int> used;

    // Generate all unique subsequences of the full unique array without repeated numbers
    generateSubsequences(a, 0, current, subsequences, used, size);


    vector<vector<int>> transformedSubsequences;

    // Transform each subsequence by multiplying terms at odd positions by -1
    for (auto& seq : subsequences) {
        vector<int> transformedSeq;
        for (int i = 0; i < seq.size(); ++i) {
            if (i % 2 == 0) {
                transformedSeq.push_back(-seq[i]);  // Multiply by -1 at odd positions (0-based index)
            } else {
                transformedSeq.push_back(seq[i]);   // Leave even positions as is
            }
        }
        transformedSubsequences.push_back(transformedSeq);
    }

    // Sort the transformed subsequences lexicographically
    sort(transformedSubsequences.begin(), transformedSubsequences.end());


    // Print the lexicographically smallest subsequence
    vector<int> smallestTransformedSeq = transformedSubsequences.front();
    for (int i = 0; i < smallestTransformedSeq.size(); ++i) {
        // Revert the transformation to get the original subsequence
        if (i % 2 == 0) {
            cout << -smallestTransformedSeq[i] << " ";
        } else {
            cout << smallestTransformedSeq[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); // this is for performance improvement (flush I/O buffer less frequently)
    cin.tie(nullptr); // this is for performance improvement (flush I/O buffer less frequently)
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
