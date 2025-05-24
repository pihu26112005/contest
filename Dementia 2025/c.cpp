#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <queue>
#include <stack>
using namespace std;
#define ll long long
#define pb push_back


string cCc(string& s, int k) {
    string result = "";
    for (char c : s) {
        char sft = 'a' + (c - 'a' + k) % 26;
        result += sft;
    }
    return result;
}

int main() {
    int t;
    cin >> t; 

    while (t--) {
        string s;
        int k;
        cin >> s >> k; 
        cout << cCc(s, k) << endl; 
    }

    return 0;
}