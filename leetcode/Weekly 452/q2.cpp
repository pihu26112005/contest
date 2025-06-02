class Solution {
    public:
        vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
            int m=grid.size();
            int n=grid[0].size();
    
            vector<vector<int>> ans(m-k+1, vector<int>(n-k+1,0));
    
            for(int i=0;i<m-k+1;i++){
                for(int j=0;j<n-k+1;j++){
                    vector<int> values;
                    for(int p=i;p<i+k;p++){
                        for(int q=j;q<j+k;q++){
                            values.push_back(grid[p][q]);
                        }
                    }
                    sort(values.begin(),values.end());
                    int mini=INT_MAX;
                    for(int t=1;t<values.size();t++){
                        if(values[t]!=values[t-1]){
                            mini=min(mini,abs(values[t]-values[t-1]));
                        }
                    }
                    ans[i][j] = mini==INT_MAX ? 0 : mini;
                }
            }
    
            return ans;
        }
    };
    
    
    // its bruteforce tc is (m*n*k to the power 4)
    
    // but o can reduce this k^4 to Ksquare log *(ksquare) + ksquare
    
    // instead of calculating each possible pair in k*k matrix 
    // i first sort htem and then jsut iterae over them 