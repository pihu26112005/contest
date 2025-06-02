class Solution {
    public:
        unordered_map<string, bool> dp;
    
        bool h(vector<int>& nums, long long& t, long long p, int i) {
            if (i == nums.size()) {
                if (p == t)
                    return true;
                else
                    return false;
            }
    
            string s = to_string(p) + "$" + to_string(i);
            if (dp.find(s) != dp.end())
                return dp[s];
    
            // exclude
            bool exc = h(nums, t, p, i + 1);
    
            // include
            // bool inc = h(nums, t, p * nums[i], tp, i + 1); // check before multiply 
            bool inc = false;
            if (p <= t && nums[i] <= t && p <= LLONG_MAX / nums[i]) {
                inc = h(nums, t, p * nums[i], i + 1);
            }
    
            return dp[s] = inc || exc;
        }
        bool checkEqualPartitions(vector<int>& nums, long long t) {
            // long long tp = 1;
            // for(int i:nums){
            //     tp*=i;
            // }
            // if(t*t!=tp)
            //     return false;
            double logTp = 0;
            for (int i : nums) {
                logTp += log(i);
            }
            if (abs(2 * log(t) - logTp) > 1e-9)
                return false;
    
            return h(nums, t, 1, 0);
        }
    };
    
    // why not 2d array for dp  - dp[i][p]
    // - hugh p valuse blow up you memory you cant have a upper bound