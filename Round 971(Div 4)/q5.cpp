#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;  // Correctly initialize t with the number of test cases
    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);   
        for(int i = 0; i < n; i++) {
            arr.push_back(k + i);
        }

        int i = 0;
        int j = n - 1;
        int rsum = arr[0];
        int lsum = arr[n - 1];

        while(i < j) {
            while(rsum < lsum && i < j) {
                i++;
                if (i < n) {
                    rsum += arr[i];
                    cout << "rsum: " << rsum << endl;
                }
            }
            while(rsum > lsum && i < j) {
                j--;
                if (j >= 0) {
                    lsum += arr[j];
                    cout << "lsum: " << lsum << endl;
                }
            }
        }
        cout << "Final i: " << i << endl;
    }
    return 0;
}
