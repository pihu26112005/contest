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

        string s = "aeiou";

        if(n<=5)
        {
            // return s.substr(0,n);
            cout << s.substr(0,n) << endl;
        }
        else
        {
            // int x = n/5;
            // int y = n%5;
            // string ans = "";
            // for(int i=0;i<x;i++)
            // {
            //     ans += s;
            // }
            // ans += s.substr(0,y);
            // cout << ans << endl;
            // int ans = 5 + (2^(n-4) - 1);
            // string res = "";
            // int extra = n-4;
            // for(int i=0;i<extra;i++)
            // {
            //     res += 'i';
            // }
            // cout << "ae" << res<<"ou" << endl;

            int x = n/5;
            int y = n%5;

            unordered_map<char,int> coutn_of_vowels;
            string ans = "";
            for(char c:s)
            {
                coutn_of_vowels[c] = x;
                if(y>0)
                {
                    coutn_of_vowels[c]++;
                    y--;
                }
            }
            for(char c:s)
            {
                for(int i=0;i<coutn_of_vowels[c];i++)
                {
                    ans += c;
                }
            }
            cout << ans << endl;
        }
    }
}