#include <bits/stdc++.h>
#include <functional>
 
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mk make_pair
#define pb push_back
#define MOD 1000000007

using namespace std;

int main() {
    // fstream InputFile, OutputFile; 
    // InputFile.open("input.txt", ios::in); OutputFile.open("output.txt", ios::out);
    // cin.rdbuf(InputFile.rdbuf()); cout.rdbuf(OutputFile.rdbuf());

    ll tc; cin >> tc;
    while (tc--){
        ll n; cin >> n;
        vector<ll> a(n), b(n);
        map<ll, ll> arr;
        for (ll i = 0; i < n; i++){
            cin >> a[i];
            arr[a[i]] = i;
        }
        sort(a.begin(), a.end());

        ll count = 1;
        for (ll i = 1; i < n; i++){
            if (arr[a[i]] > arr[a[i-1]]) count++;
        }
        
        cout << count << endl;
    }
}