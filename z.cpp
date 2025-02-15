#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    
    while (t--) {
        int n;
        cin >> n; // Number of stamps
        int totalWidth = 0;
        int maxHeight = 0;

        for (int i = 0; i < n; ++i) {
            int w, h;
            cin >> w >> h; // Read width and height of each stamp
            totalWidth += w; // Accumulate width
            maxHeight = max(maxHeight, h); // Find maximum height
        }

        // Calculate the minimum perimeter
        int minPerimeter = 2 * (totalWidth + maxHeight);
        cout << minPerimeter << endl; // Output the result
    }

    return 0;
}
