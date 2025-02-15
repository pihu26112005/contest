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
        cin>>n;
        string s;
        cin>>s;
        vector<long long > a(n);
        a[0] = (s[0] - '0') * n;
        long long j = s[0] - '0'; 
        int k = n-1;
        for(int i=1; i<n; i++){
            long long temp = (s[i] - '0')*k;  
            long long temp2 = 9*j*k;
            a[i] = temp + temp2;
            long long temp3 = s[i] - '0';
            long long  temp4 = 9*j;
            j =  (temp3 + temp4) + j;
            k--;

        }
        // sum 
        long long  sum = 0;
        for(int i=0; i<n; i++){
            sum += a[i];
        }
        cout<<sum<<endl;

    }
}