class Solution {
    public:
        string resultingString(string s) {
            if(s.length()<=1) return s;
    
            string ans="";
            stack<char> st;
            for(char c:s){
                if(st.empty())
                    st.push(c);
                else {
                    char t = st.top();
                    if(t==c+1 || t==c-1 || (t=='a'&&c=='z') || (t=='z'&&c=='a')){
                        st.pop();
                    }
                    else{
                        st.push(c);
                    }
                }
            }
            while(!st.empty()){
                char x = st.top();
                st.pop();
                ans+=x;
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };