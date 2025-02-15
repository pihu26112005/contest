#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int maxV = *max_element(a.begin(), a.end());
        
        for (int i = 0; i < m; i++) {
            char operation;
            int l, r;
            cin >> operation >> l >> r;
            
            if (l <= maxV && maxV <= r) {
                if (operation == '+') {
                    maxV++;
                } else if (operation == '-') {
                    maxV--;
                }
            }
            cout << maxV << " ";
        }
        cout << endl;
    }
    
    return 0;
}
