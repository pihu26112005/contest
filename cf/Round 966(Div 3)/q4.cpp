#include <iostream>
#include <vector>
#include <string>
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

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        string s;
        cin >> s;

        // int st = -1, en = -1;
        int i = 0, j = 0;
        vector<long long> l;
        vector<long long> r;

        while (i < n)
        {
            if (s[i] == 'L')
            {
                // st = i;
                // break;
                l.push_back(i);
            }
            i++;
        }
        while (j < n)
        {
            if (s[j] == 'R')
            {
                // en = j;
                // break;
                r.push_back(j);
            }
            j++;
        }

        vector<pair<long long, long long>> ans;
        i = 0;
        j = r.size() - 1;
        while (i < l.size() && j >= 0)
        {
            if (l[i] < r[j])
            {
                ans.push_back({l[i], r[j]});
                i++;
                j--;
            }
            else
            {
                break;
            }
        }

        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            prefix[i] = prefix[i - 1] + a[i - 1];
        }

        // Step 2: Calculate the sum using the prefix sum array
        long long sum = 0;
        for (auto p : ans)
        {
            sum += prefix[p.second + 1] - prefix[p.first];
        }

        cout << sum << endl;

        // if(st == -1 || en == -1)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }

        // // sum of all elements from s to e in a
        // int sum = 0;
        // for (int i = st; i <= en; i++)
        // {
        //     sum += a[i];
        // }
        // cout << sum << endl;
    }

    return 0;
}
