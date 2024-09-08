#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    int left=0;
    while(i<n-1 && arr[i]<arr[i+1]){
        left++;
    }
    int right=n-1;
    while(right>0 && arr[right]>arr[right-1]){
        right--;
    }
    sort(arr.begin()+left , arr.end()+right+1);
    for(int i=0; i<n; i++){
        if(arr[i]>arr[i+1]){
            cout<<"not possible";
            return 0;
        }
    }
    cout<<"possible"

}