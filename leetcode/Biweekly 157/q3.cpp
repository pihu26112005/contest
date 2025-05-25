const int MOD = 1e9 + 7;

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> m;
        for(auto i : edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]); 
        }

        int lvl = 0;
        queue<int> q;
        q.push(1);
        unordered_set<int> visited;
        visited.insert(1);

        while(!q.empty()){
            int s = q.size();
            lvl++;
            for(int i = 0; i < s; i++){
                int x = q.front();
                q.pop();
                for(int n : m[x]){
                    if(!visited.count(n)){
                        visited.insert(n);
                        q.push(n);
                    }
                }
            }
        }
        lvl--; 

        // Calculate (2^(lvl)) / 2 = 2^(lvl - 1)
        long long result = 1;
        for(int i = 0; i < lvl - 1; i++){
            result = (result * 2) % MOD;
        }

        return result%MOD;
    }
};
