class Solution {
    public:
        bool cp(long long x) {
            if (x == 1)
                return false;
            for (long long i = 2; i*i <= x; i++) {
                if (x % i == 0)
                    return false;
            }
            return true;
        }
    
        // vector<bool> sieveOfEratosthenes(long long n) {
        //     vector<bool> isPrime(n + 1, true);
        //     isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
    
        //     for (long long i = 2; i * i <= n; ++i) {
        //         if (isPrime[i]) {
        //             for (long long j = i * i; j <= n; j += i) {
        //                 isPrime[j] = false;
        //             }
        //         }
        //     }
        //     return isPrime;
        // }
    
        long long sumOfLargestPrimes(string s) {
            // long long n = stoi(s);
            // vector<bool> isp = sieveOfEratosthenes(n);
    
            long long ans = 0;
            unordered_set<long long> t2;
            long long cnt = 0;
            for (long long i = 0; i < s.length(); i++) {
                long long num = 0;
                for (long long j = i; j < s.length(); j++) {
                    num = num * 10 + (s[j] - '0');
                    if (cp(num)) {
                        // cout << "h" << x << endl;
                        t2.insert(num);
                    }
                }
            }
            vector<long long> t(t2.begin(), t2.end());
            sort(t.begin(), t.end());
            for (long long i = t.size() - 1; i >= 0; i--) {
                if (cnt < 3) {
                    ans += t[i];
                    cnt++;
                }
            }
            return ans;
        }
    };