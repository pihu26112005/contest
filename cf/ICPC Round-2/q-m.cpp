#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
 
#define ll long long
#define pii pair<ll, ll>
#define pll pair<long long, long long>
#define mk make_pair
#define pb push_back
#define MOD 1000000007

using namespace std;

ll countTrailingZeroes(ll num) {
    ll count = 0;
    while (num % 10 == 0 && num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

bool comp(ll a, ll b) {
    ll zerosA = countTrailingZeroes(a);
    ll zerosB = countTrailingZeroes(b);
    
    if (zerosA != zerosB) {
        return zerosA > zerosB;
    }
    return a < b;
}

ll countCarries(ll num1, ll num2) {
    ll carry = 0, carries = 0;
    
    while (num1 > 0 || num2 > 0) {
        ll digit1 = num1 % 10;
        ll digit2 = num2 % 10;
        
        ll sum = digit1 + digit2 + carry;
        
        if (sum >= 10) {
            carries++;
            carry = 1;
        } else {
            carry = 0; 
        }
        
        num1 /= 10;
        num2 /= 10;
    }
    
    return carries;
}

int main() {
    
    ll t;
    cin >> t;  
    
    while (t--) {
        ll n;
        cin >> n;  
        
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];  
        }

        sort(a.begin(), a.end(), comp);
        
        ll ct = 0;
        ll s = 0;
        for (ll i = 0; i < n; i++){
            ct += countCarries(s, a[i]);
            s += a[i];
        }
        cout << ct << endl;
    }
    
    return 0;
}
