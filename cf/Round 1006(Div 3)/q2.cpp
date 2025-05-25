#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int length;
        string ins;
        cin >> length >> ins;
        
        int dashCount = 0, otherCount = 0;
        for (auto &ch : ins) {
            (ch == '-') ? dashCount++ : otherCount++;
        }
        
        if (dashCount >= 2 && otherCount > 0) {
            long long leftPart = dashCount / 2;
            long long rightPart = dashCount - leftPart;
            cout << leftPart * rightPart * otherCount << '\n';
        } else {
            cout << "0\n";
        }
    }
    return 0;
}
