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
        long long n,m,q;
        cin >> n >> m >> q;
        vector<long long> teacher(m,0);
        for(long long i=0;i<m;i++)
        {
            long long x;
            cin >> x;
            teacher[i] = x;
        }
        long long david;
        cin >> david;

        vector<long long> dis(m,0);
        

        for(long long i=0;i<m;i++)
        {
            dis[i] = abs(teacher[i] - david);
        }

        if(david<n)
             david+=1;
    
        vector<long long> dis1(m,0);
        for(long long i=0;i<m;i++)
        {
            dis1[i] = abs(teacher[i] - david);
        }
        if(david)
            david-=1;

        if(david>1)
            david-=1;
        vector<long long> dis2(m,0);
        for(long long i=0;i<m;i++)
        {
            dis2[i] = abs(teacher[i] - david);
        }

        long long min = *min_element(dis.begin(),dis.end());
        long long min1 = *min_element(dis1.begin(),dis1.end());
        long long min2 = *min_element(dis2.begin(),dis2.end());

    // prlong long max of min,min1,min2
        long long ans = std::max(min,std::max(min1,min2));
        cout << ans << endl;
    }
}