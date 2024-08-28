#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int N ,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<N && arr[l]>arr[largest]){
        largest=l;
    }
    if(l<N && arr[r]>arr[largest]){
        largest=r;
    } 
    //if largest is not root
    if(largest!=i){
        swap(arr[i],arr[largest]);
        //recursively haepify the affected subtree
        heapify(arr,N , largest);
    }


}
void heapSort(int arr[], int n){
    //build heap
    for(int i=n/2-1; i>=0;i--){
        heapify(arr ,n, i);
    }
    // one by one extract an element
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    heapSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}