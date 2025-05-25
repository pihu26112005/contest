#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
   int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> D(nums.begin(), nums.end());
        unordered_set<int> pairVal;
        for(int i : D) {
            for(int j : D) {
                pairVal.insert(i ^ j);
            }
        }
        unordered_set<int> possible;
        int i = 0;
        while(i < nums.size()) {
            possible.insert(nums[i]);
            i++;
        }
        for(int p : pairVal) {
            for(int z : D) {
                int val = p ^ z;
                possible.insert(val);
            }
        }
        return possible.size();
    }


    
};
