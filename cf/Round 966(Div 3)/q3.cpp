#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n;
        cin >> n;  // Number of elements in the array
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int m;
        cin >> m;  // Number of strings
        while (m--) {
            string s;
            cin >> s;  // The string to check

            if (s.length() != n) {
                cout << "NO" << endl;
                continue;
            }

            unordered_map<int, char> mapAtoS;
            unordered_map<char, int> mapStoA;
            bool isValid = true;

            for (int i = 0; i < n; ++i) {
                int num = a[i];
                char ch = s[i];

                if (mapAtoS.count(num) && mapAtoS[num] != ch) {
                    isValid = false;
                    break;
                }

                if (mapStoA.count(ch) && mapStoA[ch] != num) {
                    isValid = false;
                    break;
                }

                mapAtoS[num] = ch;
                mapStoA[ch] = num;
            }

            if (isValid) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
