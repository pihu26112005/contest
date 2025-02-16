class Solution {
public:
    double h(double i, double j, vector<vector<int>>& sq) {
        if (j - i < 1e-6)
            return i;

        double m = i + (j - i) / 2.0;

        // Calculate area
        double larea = 0, uarea = 0;
        // int ni = -1, nj = 1e9;

        for (auto& square : sq) {
            int x = square[1], side = square[2];

            if (x + side <= m) {
                larea += (double)side * (double)side;
                // ni = max(ni, x);
            } else if (x >= m) {
                uarea += (double)side * (double)side;
                // nj = min(nj, x);
            } else {
                larea += (double)side * (double)(m - x);
                // ni = max(ni, x);
                uarea += (double)side * (double)(x + side - m);
                // nj = min(nj, x + side);
            }
        }

        if (fabs(larea - uarea) < 1e-6)
            return min(m,h(i,m,sq));

        if (larea > uarea)
            return h(i, m, sq);
        else
            return h(m, j, sq);
    }

    static bool comp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }

    double separateSquares(vector<vector<int>>& sq) {
        sort(sq.begin(), sq.end(), comp);

        double left = sq[0][1];
        double right = left;

        for (auto& square : sq)
            right = max(right, double(square[1] + square[2]));

        return h(left, right, sq);
    }
};
