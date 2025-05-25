#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read the number of integers on the board

    while (t--) {
        string a;
        cin >> a;  // Read each integer as a string

        // Check if the string starts with "10" and the remaining part is a valid integer >= 2
        if (a.substr(0, 2) == "10" && a.length() > 2) {
            string suffix = a.substr(2);
            if(suffix[0] == '0') {
                cout << "NO" << endl;
                continue;
            }
            int x = stoi(suffix);
            if (x >= 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
