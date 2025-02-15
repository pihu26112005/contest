#include <iostream>
#include <vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Function to simulate the game for one test case
char solveGame(int l, int n, int m, vector<int>& a, vector<vector<int>>& b) {
    // Initialize the starting boundaries of the submatrix
    int row_start = 0, col_start = 0;
    
    // Alternating between Tsovak and Narek: Tsovak starts first
    bool tsovak_turn = true;
    
    for (int k = 0; k < l; ++k) {
        int target = a[k]; // The current element to search for
        
        // Find the first occurrence of `target` in the current submatrix
        bool found = false;
        for (int i = row_start; i < n; ++i) {
            for (int j = col_start; j < m; ++j) {
                if (b[i][j] == target) {
                    // Update the submatrix for the next player
                    row_start = i + 1;
                    col_start = j + 1;
                    found = true;
                    break; // Exit the loop once found
                }
            }
            if (found) break; // Exit the outer loop if found
        }
        
        // If the target wasn't found in the valid submatrix, the current player loses
        if (!found) {
            return tsovak_turn ? 'N' : 'T';
        }
        
        // Alternate the turn
        tsovak_turn = !tsovak_turn;
    }
    
    // If all elements of a were found, then the last player (Narek if `l` is even, Tsovak if `l` is odd) loses
    return tsovak_turn ? 'N' : 'T';
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int l, n, m;
        cin >> l >> n >> m;
        
        vector<int> a(l);
        for (int i = 0; i < l; ++i) {
            cin >> a[i];
        }
        
        unordered_map<int, vector<pair<int,int>>> a_map;
        
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> b[i][j];
                a_map[b[i][j]].push_back({i, j});
            }
        }

        unordered_map<int, vector<pair<int,int>>> b_map;
        for (int i = 0; i < l; ++i) {
            b_map[a[i]] = a_map[a[i]];
        }

        // sort the map
        for (int i = 0; i < l; ++i) {
            sort(b_map[a[i]].begin(), b_map[a[i]].end());
        }

        unordered_map<int,pair<int,int>> c_map;
        for (int i = 0; i < l; ++i) {
            int size = b_map[a[i]].size();
            c_map[a[i]] = b_map[a[i]][ size - 1];
        }
            bool printedN = false;

         for(int i = 1; i < l; ++i) {
            int r = c_map[a[i-1]].first;
            int c = c_map[a[i-1]].second;
            r++;
            c++;
            int r2 = c_map[a[i]].first;
            int c2 = c_map[a[i]].second;
            if (r > r2 || c > c2) {
                if(i % 2 == 0) {
                    cout << "T" << endl;
                } else {
                    cout << "N" << endl;
                }
                printedN = true;
                break;
        }
         }
    if (!printedN) {
            cout << "T" << endl;
        }    
    return 0;
}

}