#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ans;
    int n;
    cin>>n;
    for(int i=0; i<n ; i++){
        int a;
        cin>>a;
        ans.push_back(a);
    }
    while(ans.size()){
        sort(ans.begin(),ans.end());
        int t=ans[0];
        int n=ans.size();
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=ans[i];
        }
        ans.clear();
        for(int i=0;i<n;i++){
            if((arr[i]-t)>0){
                ans.push_back(arr[i]-t);
            }
        }
        cout<<ans.size()<<endl;
    }
}