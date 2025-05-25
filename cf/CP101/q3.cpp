#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

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

        int oddSum = 0;
        int evenSum = 0;

        for(int i=0; i<n; i++){
            if(a[i]%2 == 0){
                evenSum += a[i];
            } else {
                oddSum += a[i];
            }
        }

        cout<<abs(oddSum - evenSum)<<endl;

    }
}