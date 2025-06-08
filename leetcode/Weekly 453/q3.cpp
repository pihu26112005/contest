const int MOD = 1e9 + 7;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        deque<int> maxDeque, minDeque;
        int left = 0;
        int sum = 0;

        vector<int> prefix(n + 1, 0);
        prefix[0] = 1;

        for (int i = 1; i <= n; ++i) {
            while (!maxDeque.empty() && nums[i - 1] > maxDeque.back())
                maxDeque.pop_back();
            maxDeque.push_back(nums[i - 1]);

            while (!minDeque.empty() && nums[i - 1] < minDeque.back())
                minDeque.pop_back();
            minDeque.push_back(nums[i - 1]);

            while (!maxDeque.empty() && !minDeque.empty() &&
                   maxDeque.front() - minDeque.front() > k) {
                if (nums[left] == maxDeque.front())
                    maxDeque.pop_front();
                if (nums[left] == minDeque.front())
                    minDeque.pop_front();
                ++left;
            }

            dp[i] =
                (prefix[i - 1] - (left > 0 ? prefix[left - 1] : 0) + MOD) % MOD;

            prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
        }

        return dp[n];
    }
};


// maxDeque: decreasing
// minDeque: increasing
// for current window , maxqueue ka front max element, second front second max element

// 2- ham left++ jab tk kr rhe hai jab tak left se i tak ek valid segement nhi banta
// if vali bn gaya left se i tak, then 
// then kahin bhi partition kro bich me farak nhi padta 
// so add dp[left] + dp[left+1] + ... + dp[i-1]
// dp[i] = prefix[i-1] - prefix[left-1]

// then we update  prefix sum 