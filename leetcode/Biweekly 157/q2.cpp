class Solution {
    public:
        int maxSubstrings(string word) {
            int n = word.size();
            vector<vector<int>> mpp(26);
            for (int i = 0; i < n; i++)
                mpp[word[i] - 'a'].push_back(i);
    
            vector<pair<int, int>> intervals;
            for (int i = 0; i < 26; i++) {
                auto& curr = mpp[i];
                for (int j = 0; j < curr.size(); j++) {
                    auto it =
                        lower_bound(curr.begin() + j + 1, curr.end(), curr[j] + 3);
                    if (it != curr.end()) {
                        intervals.emplace_back(curr[j], *it);
                    }
                }
            }
            sort(intervals.begin(), intervals.end(),
                 [](auto& a, auto& b) { return a.second < b.second; });
            // pahle vo interval aayenge jo pahle end ho rhe hai 
            int count = 0, last = -1;
            for (auto& p : intervals) {
                if (p.first > last) {
                    ++count;
                    last = p.second;
                }
            }
    
            return count;
        }
    };
    
    // 1- create map of each char to its index 
    // 2- then we try to find all possible pairs of index with number of character in between them greater than equal to 3
    // 3- then we sort them on basis of ending 
    // same char ke intervals me jo pahle end ho rha vo aayega 
    // 4- then just start se shuru hokar jitne non overlap intervall utha sakte the utha liye 