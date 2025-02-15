#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long minOperationsToMakeAlternating(int n, string& s, long long ans2) {

        if (n <= 1) return 1; // Base case to stop recursion

    unordered_map<char, int> freq;
    unordered_map<char, int> freqq;
    if(n%2 == 0)
    {
        long long ans = 0;
        // odd position 
        for(int i=0;i<n;i+=2)
        {
            freq[s[i]]++;
        }
        // sorting the ferq map 
         vector<int> freq1;
        for(auto i:freq)
        {
            freq1.push_back(i.second);
        }
        sort(freq1.begin(),freq1.end());
        for(int i=0;i<freq1.size()-1;i++)
        {
            ans+=freq1[i];
            if(ans > ans2)
            {
                return ans;
            }
        } 
        // even position
        for(int i=1;i<n;i+=2)
        {
            freqq[s[i]]++;
        }
        // sorting the ferq map
        vector<int> freq2;
        for(auto i:freqq)
        {
            freq2.push_back(i.second);
        }
        sort(freq2.begin(),freq2.end());
        for(int i=0;i<freq2.size()-1;i++)
        {
            ans+=freq2[i];
            if(ans > ans2)
            {
                return ans;
            }
        }
        return ans;
    }
    else
    {
        long long ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            // removes s[i] from the string
            string temp = s;
            temp.erase(temp.begin()+i);
            // call the function again
            ans = min(ans,minOperationsToMakeAlternating(n-1,temp,ans));
        }
        return ans+1;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // Handle the string normally
        long long ans = INT_MAX;
        cout << minOperationsToMakeAlternating(n,s,ans) << endl;
    }
    return 0;
}
