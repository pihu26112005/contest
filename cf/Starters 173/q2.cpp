#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector < int > arr;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            arr.push_back(t);
        }

        int ans = 0;
        unordered_map < int, int > m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
            if (m[arr[i]] > 1)
            {
                ans = arr[i];
                break;
            }
        }
        if (ans == 0)
            cout << -1 << endl;
        else
            cout << 1 << endl << ans << endl;
    }
    return 0;

}