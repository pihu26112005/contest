#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n;
        cin >> n;
        vector<int> b(n - 2);
        for (int i = 0; i < n - 2; i++) {
            cin >> b[i];
        }
        // goal to find 101
        bool valid = true;
        for (int i = 1; i < n - 3; i++) {
            if (b[i-1] == 1 && b[i] == 0 && b[i+1] == 1) {
                valid = false;
                break;
            }
        }
        
        if (valid)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        solve();
        
    }
    
    return 0;
}
