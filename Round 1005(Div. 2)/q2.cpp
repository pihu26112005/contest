#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

int main() {
    long long t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(n==1){
            cout << 1 << " " << 1 << endl;
            continue;
        }

        unordered_map<long long, long long> mp;
        long long distinct = 0;
        for(long long i=0;i<n;i++){
            mp[a[i]]++;
            if(mp[a[i]]==1){
                distinct++;
            }
        }
        if(distinct==1){
            cout << 0 << endl;
            continue;
        }
        long long i=0;
        long long ansl = -1;
        long long ansr = -1;
        while(i<n){
            long long l=i;
            while(i<n-1 && a[i]!=a[i+1] && mp[a[i]]==1 && mp[a[i+1]]==1){
                i++;
            }
            long long r=i;
            // if(ansl==-1 && ansr==-1){
            //     ansl=l;
            //     ansr=r;
            // }
            if(l==r){
                if(mp[a[i]]!=1){
                    if(ansl==-1 && ansr==-1){
                        // cout << 0 << endl;
                        // break;
                    }
                }
                else if(mp[a[i+1]]!=1){
                    if(ansl==-1 && ansr==-1){
                        ansl=l;
                        ansr=r;
                        break;
                    }
                    else if(r-l>ansr-ansl){
                        ansl=l;
                        ansr=r;
                    }
                }
            }
            else if(r-l>ansr-ansl){
                ansl=l;
                ansr=r;
            }
            i++;
        }
        if(ansl==-1 && ansr==-1){
            cout << 0 << endl;
        }
        else{
            cout << ansl+1 << " " << ansr+1 << endl;
        }
    }
    
    return 0;
}