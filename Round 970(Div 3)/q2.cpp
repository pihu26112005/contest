#include <iostream>
#include <cmath>
using namespace std;

bool isbm(const string &s, int k, int n) {
    bool iz = false;
    if(k!=2)
    {
        for(int i = 0; i < n; i++) {
        if (s[i] == '0')
            return true;
    }
    
    }
    else
    {
        iz = true;
    }
    // Checking first and last row
    for (int i = 0; i < k; i++) {
        if (s[i] != '1' || s[(k-1)*k + i] != '1')
            return false;
    }
    
    // Checking first and last column
    for (int i = 1; i < k - 1; i++) {
        if (s[i*k] != '1' || s[i*k + k - 1] != '1')
            return false;
    }
    
    // All checks passed
    return true && iz;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        int k = sqrt(n);
        if (k * k == n && isbm(s, k, n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
