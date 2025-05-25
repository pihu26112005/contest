#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < row.size(); ++j) {
                if (row[j] == '#') {
                    result.push_back(j + 1); // store 1-based index
                    break;
                }
            }
        }
        
        // Print the result in reverse order (bottom to top)
        for (int i = n - 1; i >= 0; --i) {
            cout << result[i]<<" " ;
        }
        cout << endl;
    }
    
    return 0;
}
