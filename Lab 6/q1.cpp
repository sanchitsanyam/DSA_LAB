#include<bits/stdc++.h>
using namespace std;
int power(int x, int n){
    if(n==0)return 1;
    int t=power(x , n/2);
    if(n%2==0){
       return t* t; 
    }
    else{
        return t * t *x;
    }
}
int main(){
    cout<< power(2,3);
}