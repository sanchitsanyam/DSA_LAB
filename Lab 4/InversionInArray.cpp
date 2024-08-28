#include<bits/stdc++.h>
using namespace std;
int merge(int arr[] ,int p ,int q ,int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1] ,M[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[i+p];
    }
    for(int i=0;i<n2;i++){
        M[i]=arr[i+q+1];
    }
    int res=0;
    int i=0,j=0, k=p;
    while(i<n1 && j<n2){
        if(L[i]<=M[j]){
            arr[k]=L[i];
            i++;
            k++;
        }
        else{
            arr[k]=M[j];
            j++;
            k++;
            res+=(n1-i);
        }
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=M[j];
        j++;
        k++;
    }
    return res;
}
int countInversion(int  arr[],int l ,int r){
    int res=0;
    if(l<r){
        int m=(l+r)/2;
        res+=countInversion(arr,l,m);
        res+=countInversion(arr,m+1,r);
        res+=merge(arr, l ,m,r);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<countInversion(arr, 0 ,n-1);
    

}