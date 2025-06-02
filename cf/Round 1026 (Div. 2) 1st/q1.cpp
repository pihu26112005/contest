#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        sort(arr.begin(), arr.end());
        int i=0;
        int j=n-1;

        if ((arr[i] % 2) != (arr[j] % 2)) {
            int i2 = 1;
            int j2 = n - 2;
            while (i2 < n && (arr[i] % 2 == arr[i2] % 2)) i2++;
            while (j2 >= 0 && (arr[j] % 2 == arr[j2] % 2)) j2--;
            cout << min(i2, n - j2 - 1) << endl;
        }
        else {
            cout << 0 << endl;
        }
        
    }
}