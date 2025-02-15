#include <iostream>
#include <string>
using namespace std;

bool isstringgood(const string &s) {
    int n = s.length();
    
    if(s[0]!=s[n-1]){
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        if (isstringgood(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
