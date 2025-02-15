// 1 rotate B to become get minimum number at first.

// 2 since number are unique only 1 case is possible

// 3 iterate for 0->n-m in A and 0->m in B

// 4 if u find a subarray of size m greater then B then replace that subarray with b.

// 5 then do same for i+1

#include <bits/stdc++.h>
using namespace std;

vector<int>ans(vector<int>& b) {
    int idx = min_element(b.begin(), b.end()) - b.begin();
    rotate(b.begin(), b.begin() + idx, b.end());
    return b;
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        vector<int>b(m);
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        
        b=ans(b);
        
        for(int i=0;i<=n-m;i++){
            
            bool poss=true;
            
            for(int j=i;j<i+m;j++){
                if(b[j-i]>a[j]){
                    poss=false;
                    break;
                }
                else if(b[j-i]==a[j]){
                    continue;
                }
                else{
                    poss=true;
                    break;
                }
            }
            
            if(poss==true){
            copy(b.begin(), b.end(), a.begin() + i);   
            }
        }
        
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
    }
}