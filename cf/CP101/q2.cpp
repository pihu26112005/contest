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
        int count = 0;
        while(n){
            n = n & (n-1);
            count++;
        }
        cout << count << endl;


    }
}