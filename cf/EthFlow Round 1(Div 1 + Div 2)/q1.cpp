#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        int ans = 0; // To count the number of ans required
        
        for (char c : s) {
            if (c == '1') {
                // if (!inBlock) {
                    ans++;
                    // inBlock = true; // Start a new block
                // }
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
