#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> F(n, 0);
    vector<bool> visited(n, false);
    string s;
    
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--; // Convert to zero-indexed
    }
    
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> cycle;
            int countBlack = 0;
            int j = i;
            
            while (!visited[j]) {
                visited[j] = true;
                cycle.push_back(j);
                if (s[j] == '0') countBlack++;
                j = p[j];
            }
            
            for (int idx : cycle) {
                F[idx] = countBlack;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << F[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
