#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        unordered_map<char, int> char_freq;
        for (char c : s) {
            char_freq[c]++;
        }
        string unique_chars;
        while(n!=0)
        {
            for (auto it = char_freq.begin(); it != char_freq.end(); ++it) {
                if (it->second > 0) {
                    unique_chars += it->first;
                    it->second--;
                    n--;
                }
            }
        }

        cout << unique_chars << endl;

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
