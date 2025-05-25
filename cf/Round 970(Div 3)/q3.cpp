#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long l, r;
        cin >> l >> r;
        
        long long maximim_diffrence = r - l;
        long long k = 1;
        while (k * (k - 1) / 2 <= maximim_diffrence) {
            k++;
        }
        
        cout << k - 1 << endl;
    }
    
    return 0;
}
