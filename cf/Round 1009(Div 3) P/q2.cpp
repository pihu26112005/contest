#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        int s=0;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            s+=temp;
            arr.push_back(temp);
        }

        s=s-(n-1);
        cout<<s<<endl;
    }
    return 0;
}