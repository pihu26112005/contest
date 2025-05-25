#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int k, xf, yf;
        cin >> xf >> yf >>k;
        int result;

        if(yf>=xf)
        {
            result = yf%k == 0 ? 2*( yf/k) : 2*( yf/k + 1);
        }
        else
        {
            result = xf%k == 0 ? 2*( xf/k) -1: 2*( xf/k + 1) -1;
        }
        
        
        
        cout << result << endl;
    }
    
    return 0;
}
