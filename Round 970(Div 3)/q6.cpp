#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long modInverse(long long a, long long m) {
    long long res = 1;
    long long p = m - 2;
    while (p) {
        if (p & 1) res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum = (sum + a[i]) ;
        }

        long long P = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum - a[i] );
            P = (P + a[i] * sum);
        }

        long long Q = (n * (n - 1) / 2);
        long long Q_inv = modInverse(Q, MOD);
        long long result = (P * Q_inv) % MOD;

        cout << result << endl;
    }
    return 0;
}
