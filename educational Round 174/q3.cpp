#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long
#define MOD 998244353
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(){
    int n;
        cin >> n;
        
        ll s1 = 0;
        ll cnt = 0;
        ll t = 0;
        ll groups = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int num : a) {
            if (num == 1) {
                s1 = (s1 + 1) % MOD;
                cnt++;
            } else if (num == 2) {
                s1 = (s1 * 2) % MOD;
            } else if (num == 3) {
                t = (t + s1) % MOD;
                groups = (groups + cnt) % MOD;
            }
        }
        ll ans = (t - groups + MOD) % MOD;
        cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
       solve();
    }

    return 0;
}
