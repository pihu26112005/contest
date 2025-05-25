#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int l, r;
        cin >> l >> r;
        
        int count_num = 0;
        
        for (int i = l; i <= r - 2; i++) {
            if (gcd(i, i+1) == 1 && gcd(i+1, i+2) == 1 && gcd(i, i+2) == 1) {
                cout<<i<<" "<<i+1<<" "<<i+2<<endl;
                count_num++;
                i += 2;  // Skip the next two numbers since we used them
            }
        }
        
        cout << count_num << endl;
    }
    
    return 0;
}
