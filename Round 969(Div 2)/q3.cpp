#include<iostream>
#include<climits>
using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, a, b;
        cin >> n >> a >> b;
        int* c = new int[n];
        int max_num = INT_MIN;
        for(int j = 0; j < n; j++) {
            cin >> c[j];
            max_num = max(max_num, c[j]);
        }
        int GCD = gcd(min(a, b), max(a, b));
        int l = GCD / 2;
        for(int j = 0; j < n; j++) {
            while(abs(max_num - c[j] )> l) {
                c[j] += GCD;
            }
        }
        int min_num = INT_MAX;
        max_num = INT_MIN;
        for(int j = 0; j < n; j++) {
            min_num = min(min_num, c[j]);
            max_num = max(max_num, c[j]);
        }
        // cout << GCD << " " << l << endl;
        // for(int j = 0; j < n; j++)
        //     cout << c[j] << " ";
        cout << max_num - min_num << endl;
    }
}