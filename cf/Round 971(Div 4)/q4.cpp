#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int count_right_triangles(int n, vector<pair<int, int>>& points) {
    unordered_map<int, int> y0_count;  // Count of points at y = 0 for each x
    unordered_map<int, int> y1_count;  // Count of points at y = 1 for each x
    unordered_map<int, int> x_count;   // Count of points for each x-coordinate

    // Populate the dictionaries
    for (int i = 0; i < n; i++) {
        int x = points[i].first;
        int y = points[i].second;
        if (y == 0) {
            y0_count[x]++;
        } else {
            y1_count[x]++;
        }
        x_count[x]++;
    }

    // Calculate the number of right triangles
    int right_triangles = 0;

    // Vertical leg right triangles
    for (auto& entry : x_count) {
        int x = entry.first;
        if (y0_count[x] > 0 && y1_count[x] > 0) {
            right_triangles += y0_count[x] * y1_count[x];
        }
    }

    // Horizontal leg right triangles
    for (auto& entry : x_count) {
        int x = entry.first;
        if (x_count[x] >= 2) {
            right_triangles += (x_count[x] * (x_count[x] - 1)) / 2;
        }
    }

    return right_triangles;
}

int main() {
    int t;
    cin >> t;
    vector<int> results;

    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> points(n);

        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }

        int result = count_right_triangles(n, points);
        results.push_back(result);
    }

    for (const auto& res : results) {
        cout << res << endl;
    }

    return 0;
}
