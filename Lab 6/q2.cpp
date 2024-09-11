#include<bits/stdc++.h>
using namespace std;
bool checkIsSum(int i , vector<int>& arr, int sum ){
    if(sum==0)return true;
    if(i==0) return false;
    if(arr[i-1]>sum){
       return checkIsSum(i-1 , arr,  sum ); 
    }
    return checkIsSum(i-1 , arr,  sum )||checkIsSum( i-1 ,  arr,  sum-arr[i-1] );
     
    
}

int main(){
    int n;
    cin>> n;
    int sum;
    cin>>sum;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
        cin>> arr[i];
    }
    
    cout<< checkIsSum(n,arr ,sum );


}