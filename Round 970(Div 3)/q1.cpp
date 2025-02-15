#include <iostream>
using namespace std;

// prnidiw
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b;
        cin >> a >> b;

        if(a==0 || b==0){
            int unique = a+b;
            if(unique%2 == 0){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        else if(a%2 == 0 && b%2 == 0) {
            cout << "YES" << endl;
        } else if(a%2 == 0 && b%2 != 0) {
            cout << "YES" << endl;
        } else if(a%2 != 0 && b%2 == 0) {
            cout << "NO" << endl;
        } else if(a%2 != 0 && b%2 != 0) {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
