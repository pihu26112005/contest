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
        string s;
        cin >> s;
        int n = s.size();
        vector<char> vowelInS;
        vector<char> consonantInS;
        vector<int> vowelIndexInS;
        vector<int> consonantIndexInS;

        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                vowelInS.push_back(s[i]);
                vowelIndexInS.push_back(i);
            } else {
                consonantInS.push_back(s[i]);
                consonantIndexInS.push_back(i);
            }
        }

        sort(vowelInS.begin(), vowelInS.end());
        sort(consonantInS.begin(), consonantInS.end());

        vector<char> ans(n);
        int vowelIndex = 0;
        for(char c: vowelInS){
            ans[vowelIndexInS[vowelIndex]] = c;
            vowelIndex++;
        }

        int consonantIndex = 0;
        for(char c: consonantInS){
            ans[consonantIndexInS[consonantIndex]] = c;
            consonantIndex++;
        }

        // for(char c: ans){
        //     cout << c;
        // }

        bool isSorted = true;
        for(int i=0; i<n-1; i++){
            if(ans[i] > ans[i+1]){
                isSorted = false;
                break;
            }
        }

        if(isSorted){
            cout << "Pass" << endl;
        } else {
            cout << "Fail" << endl;
        }
        

    }
}