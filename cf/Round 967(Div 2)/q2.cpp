#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n % 2 == 0)
        {
            cout << "-1";
            cout << endl;
        }
    else
    {
        vector<int> v(n);
        // start filling from middle since n is odd, middle element is 1 , thn left right go ex --> 53124 for n = 5
        int i = 0, j = n - 1;
        for (int k = n; k > 0; k--)
        {
            if (k % 2 == 1)
            { // odd
                v[i] = k;
                i++;
            }
            else
            { // even
                v[j] = k;
                j--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
