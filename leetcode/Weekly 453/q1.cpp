class Solution {
    public:
        bool canMakeEqual(vector<int>& nums, int k) {
            int mv=INT_MAX;
            int n=nums.size();
            vector<int> nums1=nums;
            vector<int> nums2=nums;
            int t=0;
            for(int i=0;i<n-1;i++){
                if(nums1[i]!=1){
                    nums1[i]=1;
                    nums1[i+1]=-1*nums1[i+1];
                    t++;
                }
            }
            if(nums1[n-1]==-1) t=INT_MAX;
            mv=min(mv,t);
            t=0;
            for(int i=0;i<n-1;i++){
                if(nums2[i]!=-1){
                    nums2[i]=-1;
                    nums2[i+1]=-1*nums2[i+1];
                    t++;
                }
            }
            if(nums2[n-1]==1) t=INT_MAX;
            mv=min(mv,t);
            return mv<=k;
        }
    };