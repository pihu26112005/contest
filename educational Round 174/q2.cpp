#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long
#define MOD 1000000007
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        unordered_map<int, int> steptoCount;
        cin >> n >> m;
        vector<vector<int>> cells(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> cells[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int color = cells[i][j];
                if (steptoCount.find(color) == steptoCount.end())
                {
                    steptoCount[color] = 1;
                }

                if (i < n - 1 && cells[i + 1][j] == color)
                    steptoCount[color] = 2;
                if (j < m - 1 && cells[i][j + 1] == color)
                    steptoCount[color] = 2;
            }
        }

        int mg = 0;
        int t = 0;
        for (auto &p : steptoCount)
        {
            mg = max(mg, p.second);
            t += p.second;
        }
        cout << (t - mg) << "\n";
    }

    return 0;
}
