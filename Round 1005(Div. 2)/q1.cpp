// #include <iostream>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int n;
//         string s;
//         cin >> n >> s;
//         int i=0;
//         while(i<n && s[i]=='0') {
//             i++;
//         }
//         if(i==n) {
//             cout << 0 << endl;
//             continue;
//         }
//         int ans = 1;
//         bool one = true;
//         for(; i<n; i++) {
//             if(one) {
//                 if(s[i]=='0') {
//                     ans++;
//                     one = false;
//                 }
//             } else {
//                 if(s[i]=='1') {
//                     ans++;
//                     one = true;
//                 }
//             }
//         }
//         cout << ans << endl;
//     }
    
//     return 0;
// }



#include <iostream>
using namespace std;

int countAlternatingSegments(const string& s, int n) {
    int i = 0;
    while (i < n && s[i] == '0') {
        i++;
    }
    if (i == n) {
        return 0;
    }
    
    int ans = 1;
    bool one = true;
    for (; i < n; i++) {
        if (one && s[i] == '0') {
            ans++;
            one = false;
        } else if (!one && s[i] == '1') {
            ans++;
            one = true;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << countAlternatingSegments(s, n) << endl;
    }
    
    return 0;
}