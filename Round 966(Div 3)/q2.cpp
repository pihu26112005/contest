#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int n;
        cin >> n;  // Number of seats and passengers
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];  // Read the seat occupied by the i-th passenger
        }
        
        set<int> occupied_seats;
        occupied_seats.insert(a[0]);  // First passenger can sit anywhere
        
        bool valid = true;
        
        // Process subsequent passengers
        for (int i = 1; i < n; ++i) {
            int seat = a[i];
            // Check if the current seat is adjacent to an already occupied seat
            if (occupied_seats.count(seat - 1) || occupied_seats.count(seat + 1)) {
                occupied_seats.insert(seat);  // Mark the seat as occupied
            } else {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
