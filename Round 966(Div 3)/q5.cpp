#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int w;
        cin >> w;

        vector<int> heights(w);
        for (int i = 0; i < w; i++) {
            cin >> heights[i];
        }

        // Sort the heights in descending order
        sort(heights.rbegin(), heights.rend());

        int max_possible_squares = (n - k + 1) * (m - k + 1);

        // Find the sum of the top 'max_possible_squares' heights
        long long max_spectacle = 0;
        for (int i = 0; i < min(w, max_possible_squares); i++) {
            max_spectacle += heights[i];
        }

        cout << max_spectacle << endl;
    }

    return 0;
}
