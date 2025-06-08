class Solution {
    public:
        long long h(int c, int i, int flag, vector<int>& p,
                    vector<vector<vector<long long>>>& dp) {
            if (i >= p.size()) { 
                return flag == 0 ? 0 : INT_MIN;// for mid transactions
            }
            if (dp[i][flag][c] != -1)
                return dp[i][flag][c];
            long long profit = INT_MIN;
            profit = max(profit, h(c, i + 1, flag, p, dp));
            if (flag == 0) { 
                // profit = max(-p[i] + h(c, i + 1, 1, p, dp), +p[i] + h(c, i + 1, 2, p, dp));
                // dont know why inko do lines me alag krke sahi ho gaya 
                profit = max(profit, -p[i] + h(c, i + 1, 1, p, dp)); 
                profit = max(profit, +p[i] + h(c, i + 1, 2, p, dp)); 
            } else if (flag == 1) {
                if (c > 0)
                    profit = max(profit, p[i] + h(c - 1, i + 1, 0, p, dp));
            } else if (flag == 2) {
                if (c > 0)
                    profit = max(profit, -p[i] + h(c - 1, i + 1, 0, p, dp));
            }
    
            dp[i][flag][c] = profit;
            return profit;
        }
    
        long long maximumProfit(vector<int>& p, int k) {
            int n=p.size();
            vector<vector<vector<long long>>> dp(
                p.size() + 1,
                vector<vector<long long>>(4, vector<long long>(k + 1, -1)));
            return h(k, 0, 0, p, dp);
            //  for (int i = n - 1; i >= 0; i--) {
            //     for (int flag = 2; flag >=0; flag--) {
            //         for (int c = 0; c <= k; c++) {
            //             long long profit = INT_MIN;
            //             profit = max(profit, dp[i + 1][flag][c]);
            //             if (flag == 0) {
            //                 profit = max(profit, -p[i] + dp[i + 1][1][c]); 
            //                 profit = max(profit, +p[i] + dp[i + 1][2][c]);
            //             } else if (flag == 1) {
            //                 if(c>0)
            //                     profit = max(profit, p[i] + dp[i + 1][0][c - 1]); 
            //             } else if (flag == 2) {
            //                 if(c>0)
            //                     profit = max(profit, -p[i] + dp[i + 1][0][c - 1]); 
            //             }
    
            //             dp[i][flag][c] = profit;
            //         }
            //     }
            // }
            // return dp[0][0][k];
        }
    };
    
    // flag=true --> i can start a new trnasaction
    // k-1 tab hi krna hai jab transaction end ho rhi ho 
    // mid transactions ka check rakhna hai 