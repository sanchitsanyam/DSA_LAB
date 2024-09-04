#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    // vector<int> ans(n-1);
    int sum=0;
    for(int i=1;i<=n-1;i++){
        int a;
        cin>>a;
        // ans[i]=a;
        sum+=a;
    }
    cout<<sum<<" ";
    int k=n*(n+1);
    k/=2;
    cout<< k-sum;
}
