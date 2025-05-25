#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int total, target, step;
        cin >> total >> target >> step;

        if (target == 0) {
            cout << 0 << '\n';
            continue;
        }

        int req_steps = (abs(target) + step - 1) / step; 
        
        cout << (req_steps <= total ? req_steps : -1) << '\n';
    }
    
    return 0;
}
