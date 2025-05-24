#include <cmath> 

class Solution {
public:

    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> m;

        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3){
            for(int i:nums){
                for(int j:nums){
                    for(int k:nums){
                        int t=i^j^k;
                         // if (m.find(t) == m.end())
                         //    m[t] = true;
                        m.insert(i^j^k);
                    }
                }
            }
            return m.size();
        }


        else {
            int t=-1;
            for(int i=0;i<nums.size();i++)
                t=max(t,nums[i]);
            
            int b = static_cast<int>(log2(t));
            // if(b&1)
            //     return pow(2,b+1);
            // else 
                return pow(2,b+1);
        }
    }
};




