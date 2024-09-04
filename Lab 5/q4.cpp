#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    sort(arr.begin(),arr.end());
    if(n%2==0){
        cout<<(arr[n/2]+arr[(n/2) +1])/2<<endl;
    }
    else{
        cout<<arr[(n/2)+1]<<endl;
    }
}