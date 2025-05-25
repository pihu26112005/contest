class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        // if (k == 1) return !s.empty();  
        
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && s[j] == s[j + 1]) {
                j++;
                if(j==n-2 && s[j]==s[j+1])
                    j++;
            }
            if (j - i + 1 == k) return true;
            i = j + 1;  
        }
        return false;
    }
};
