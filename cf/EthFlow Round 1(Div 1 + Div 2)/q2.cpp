#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t; 
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
       vector<int>arr(n);
         for (int i = 0; i < n; i++) {
              cin >>arr[i];
         }
          
        for(int i=0;i<n;i++){
            int val =arr[i];
            int r = ((n-1)-i)*2;
            int l = i*2;
            int t = max(r,l);
            if(val-t <=0)
            {
                cout<<"NO"<<endl;
                goto end;
            }
        }
        cout<<"YES"<<endl;
        end:;
    }
    
    return 0;
}
