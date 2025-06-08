class Solution {
    public:
        int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
            unordered_map<int,int> m;
            int n=x.size();
            for(int i=0;i<n;i++){
                if(m.find(x[i])!=m.end()){
                    m[x[i]]=max(m[x[i]],y[i]);
                }
                else{
                    m[x[i]]=y[i];
                }
            }
            vector<int> t;
            for(auto i:m)
                t.push_back(i.second);
            if(t.size()<3)
                return -1;
            sort(t.begin(),t.end());
            int k=t.size();
            return t[k-1]+t[k-2]+t[k-3];
        }
    };