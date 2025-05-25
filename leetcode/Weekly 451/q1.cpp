class Solution {
    public:
        long long minCuttingCost(int n, int m, int k) {
            if(k>=n && k>=m)
                return 0;
            else if(k>=n && k<m){
                long long len1 = k;
                long long len2 = m-len1;
                return len1*len2;
            }
            else if(k<n && k>=m){
                long long len1 = k;
                long long len2 = n-len1;
                return len1*len2;
            }
            else{
                long long len1 = n-k;
                long long len2 = m-k;
                return len1*len2;
            }
        }
    };