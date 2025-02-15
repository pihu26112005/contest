#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;   
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int k;
        if(n%2 == 0){
            k = n/2;
        } else {
            k = n/2 + 1;
        }

        // print maximum possible sum of k elements
        int sum = 0;
        // lop only k times 
        for(int i=n-1; i>=0; i=i-2){
            // cout << a[i] << " ";
            if(k == 0){
                break;
            }
            sum += a[i];
            k--;
            
        }
        cout << sum << endl;
    }
}