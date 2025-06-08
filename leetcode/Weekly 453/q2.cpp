#define MOD 1000000007
class Solution {
public:
    long long f(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        return (n % MOD) * (f(n - 1) % MOD) % MOD;
    }

    int countPermutations(vector<int>& c) {
        int n = c.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        for (int i = 1; i < n; i++) {
            if (c[i] <= c[0])
                return 0;
        }
        return f(n - 1) % MOD;
    }
};
