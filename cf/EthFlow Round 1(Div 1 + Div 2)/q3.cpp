#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long maxSum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maxSum += a[i];
    }
    long long sum = 0;
    bool dir = true;
    int l = 0;
    int r = a.size() - 1;
    while(l < r) {
        if(dir) {
            for(int i = l; i < r; i++) {
                a[i] = a[i] - a[i + 1];
                sum += 1LL * a[i];
            }
            r--;
        }
        else {
            for(int i = r; i > l; i--) {
                a[i] = a[i] - a[i - 1];
                sum += 1LL * a[i];
            }
            l++;
        }
        maxSum = max(maxSum, sum);
        dir = !dir;
        sum = 0LL;
    }
    maxSum = max(maxSum, 1LL * a[l]);
    cout << maxSum << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}