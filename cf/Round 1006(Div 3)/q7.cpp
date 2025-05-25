#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int md = 1e9 + 7;
const int INV_2 = 500000004;
const int INV_6 = 166666668;

long long rm(int number, int base) {
    if (base == 1) return 0;
    long long reversed = 0;
    int temp = number;
    while (temp > 0) {
        int digit = temp % base;
        reversed = reversed * base + digit;
        temp /= base;
    }
    return reversed % md;
}

long long sum_mr(long long start, long long end) {
    if (start > end) return 0;
    long long sum_end = (end % md) * ((end + 1) % md) % md;
    sum_end = sum_end * INV_2 % md;
    long long sum_start = ((start - 1) % md) * (start % md) % md;
    sum_start = sum_start * INV_2 % md;
    return (sum_end - sum_start + md) % md;
}

long long sum_squared_mod_range(long long start, long long end) {
    if (start > end) return 0;
    
    long long sum_end = (end % md) * ((end + 1) % md) % md;
    sum_end = sum_end * ((2 * end + 1) % md) % md;
    sum_end = sum_end * INV_6 % md;

    long long start_minus1 = (start - 1) % md;
    long long sum_start = start_minus1 * (start % md) % md;
    sum_start = sum_start * ((2 * start_minus1 + 1) % md) % md;
    sum_start = sum_start * INV_6 % md;

    return (sum_end - sum_start + md) % md;
}

void process_test_case() {
    int num;
    long long limit;
    cin >> num >> limit;

    long long result = 0;
    long long min_val = min((long long)num, limit);

    if (min_val >= 2) {
        int sqrt_val = sqrt(num);
        while ((long long)(sqrt_val + 1) * (sqrt_val + 1) <= num) sqrt_val++;
        sqrt_val = min((long long)sqrt_val, min_val);

        // Phase 1: Base p from 2 to sqrt_val
        for (int base = 2; base <= sqrt_val; ++base) {
            long long rev_value = rm(num, base);
            result = (result + rev_value) % md;
        }

        // Phase 2: Handling q from 1 to max_q
        int max_q = sqrt(num);
        for (int q = 1; q <= max_q; ++q) {
            long long lower_bound = (num / (q + 1)) + 1;
            long long upper_bound = num / q;

            long long start_p = max(lower_bound, (long long)sqrt_val + 1);
            long long end_p = min(upper_bound, min_val);

            if (start_p > end_p) continue;

            long long sum_p = sum_mr(start_p, end_p);
            long long sum_p_sq = sum_squared_mod_range(start_p, end_p);
            long long count_mod = (end_p - start_p + 1) % md;

            long long term1 = ((num % md) * sum_p) % md;
            long long term2 = ((q % md) * sum_p_sq) % md;
            term2 = (term2 % md + md) % md;
            long long term3 = ((q % md) * count_mod) % md;

            long long segment_sum = (term1 - term2 + term3) % md;
            if (segment_sum < 0) segment_sum += md;

            result = (result + segment_sum) % md;
        }
    }

    // Extra part for p > num
    if (limit > num) {
        long long extra_count = (limit - num) % md;
        result = (result + (extra_count * (num % md)) % md) % md;
    }

    result = (result % md + md) % md;
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        process_test_case();
    }

    return 0;
}
