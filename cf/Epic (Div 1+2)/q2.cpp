#include <iostream>
#include <vector>
using namespace std;

string find_winner(int n, vector<int>& a, vector<int>& b) {
    // Compare the last elements of both arrays
    if (a.back() == b.back()) {
        return "Bob";
    } else {
        return "Alice";
    }
}

int alice_move(int n, vector<int>& a, vector<int>& b, int removed_element) {
    if (removed_element != a.front()) {
        if (a.front() != b.front() && a.front() != b.back()) {
            int removed = a.front();
            a.erase(a.begin());
            return removed;
        }
    }
    if (removed_element != a.back()) {
        if (a.back() != b.front() && a.back() != b.back()) {
            int removed = a.back();
            a.pop_back();
            return removed;
        }
    }
    if (a.front() != b.front() && a.front() != b.back()) {
        int removed = a.front();
        a.erase(a.begin());
        return removed;
    }
    int removed = a.back();
    a.pop_back();
    return removed;
}

int bob_move(int n, vector<int>& b, vector<int>& a, int removed_element) {
    if (removed_element == b.front()) {
        int removed = b.front();
        b.erase(b.begin());
        return removed;
    } else if (removed_element == b.back()) {
        int removed = b.back();
        b.pop_back();
        return removed;
    } else {
        if (b.front() != a.front() && b.front() != a.back()) {
            int removed = b.back();
            b.pop_back();
            return removed;
        } else {
            int removed = b.front();
            b.erase(b.begin());
            return removed;
        }
    }
}

int main() {
    int t;  // number of test cases
    cin >> t;
    vector<string> results;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        for (int j = 0; j < n; ++j) {
            cin >> b[j];
        }

        int removed_element = 0;

        for (int j = 0; j < n - 1; ++j) {
            removed_element = alice_move(n, a, b, removed_element);
            // cout << "alice removed " << removed_element << endl;
            removed_element = bob_move(n, b, a, removed_element);
            // cout << "bob removed " << removed_element << endl;
        }

        results.push_back(find_winner(n, a, b));
    }

    // Output results for all test cases
    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}