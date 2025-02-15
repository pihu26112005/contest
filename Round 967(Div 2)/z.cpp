#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

void generateSubsequences(vector<int>& a, int index, vector<int>& current, set<vector<int>>& subsequences, unordered_set<int>& used, int size) {
    if (current.size() == size) {
        subsequences.insert(current);
        return;
    }
    
    // Base case: if we've reached the end of the array, return
    if (index == a.size()) {
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

int main() {
    vector<int> a = {5 ,2, 1, 7, 9, 7, 2, 5, 5, 2};
    set<vector<int>> subsequences;
    vector<int> current;
    unordered_set<int> used;

    // Generate all unique subsequences without repeated numbers
    generateSubsequences(a, 0, current, subsequences, used,5);

    // Print the unique subsequences
    for (const auto& seq : subsequences) {
        cout << "{ ";
        for (int num : seq) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
