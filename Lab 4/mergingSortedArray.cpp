#include<bits/stdc++.h>
using namespace std;
void merge(int arr[] ,int L[] ,int M[] ,int n1,int n2){

    int i=0,j=0, k=0;
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
}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    int L[n1];
    int M[n2];
    cout<<"Enter L array"<<endl;
    for(int i=0; i<n1; i++){
        cin>>L[i];
    }
    cout<<"enter M array"<<endl;
    for(int i=0; i<n2; i++){
        cin>>M[i];
    }

    int arr[n1+n2];
    merge(arr, L,M,n1,n2);
    for(int i=0; i<n1+n2; i++){
        cout<<arr[i]<<" ";
    }

}
