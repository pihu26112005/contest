#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        bool turtleTurn = true;
        int m = n;
        while (m > 1)
        {
            if (turtleTurn)
            {
                // extract max from a, in between index 0 and m-2
                int maxIndex = 0;
                for (int i = 0; i < m - 1; i++)
                {
                    if (a[i] >= a[maxIndex])
                    {
                        maxIndex = i;
                    }
                }
                if(maxIndex-1>=0)
                    maxIndex = maxIndex -1;
                a[maxIndex] = max(a[maxIndex], a[maxIndex + 1]);
                // remove the element at maxIndex +1
                a.erase(a.begin() + maxIndex + 1);
                m--;
                turtleTurn = false;
            }
            else
            {
                // extract min from a, in between index 0 and m-2
                int minIndex = 0;
                for (int i = 0; i < m - 1; i++)
                {
                    if (a[i] <= a[minIndex])
                    {
                        minIndex = i;
                    }
                }
                if(minIndex+1<m-1)
                    minIndex = minIndex +1;
                a[minIndex] = min(a[minIndex], a[minIndex + 1]);
                // remove the element at minIndex +1
                a.erase(a.begin() + minIndex + 1);
                m--;
                turtleTurn = true;
            }
        }

        // The resulting a[0] is the final value after all optimal moves
        cout << a[0] << endl;

        // // sort array and return the middle element
        // sort(a.begin(), a.end());
        // cout << a[n / 2] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
