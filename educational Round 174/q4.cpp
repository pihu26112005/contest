#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long
#define MOD 1000000007
#define endl "\n"
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int i = 0;
        int j = n - 1;

        while (i < j && s[i] == s[j])
        {
            i++;
            j--;
        }

        // cout<<"i,j"<<i<<j<<endl;
        if(i>=j){
            cout<<0<<endl;
            continue;
        }

        int dis_cnt = 0;
        unordered_map<char, bool> mp;
        for (int k = i; k <= j; k++)
        {
            if (mp.find(s[k]) == mp.end())
            {
                dis_cnt++;
                mp[s[k]] = true;
            }
        }

        unordered_map<char, bool> aachukaHaiYaNi;
        int cnt = 0;
        int fj = i;
        for (int k = i; k <= j; k++)
        {
            if (aachukaHaiYaNi.find(s[k]) == aachukaHaiYaNi.end())
            {
                cnt++;
                aachukaHaiYaNi[s[k]] = true;
            }
            if (cnt == dis_cnt)
            {
                break;
            }
            fj++;
        }
        j = fj;
        // cout << "i,j" << i << j << endl;

        if (j == n / 2 - 1)
        {
            int ti = j;
            int tj = j + 1;
            while (ti >= 0 && tj < n && s[ti] == s[tj])
            {
                ti--;
                tj++;
            }
            // cout<<"ti,tj"<<ti<<tj<<endl;
            j = ti;
        }
        // cout<<"i,j"<<i<<j<<endl;
        cout<<j-i+1<<endl;
    }
    return 0;
}
