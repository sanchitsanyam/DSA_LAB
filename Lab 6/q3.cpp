#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1 ,s2;
    cin>>s1>>s2;
    
    int m=s1.size();
    int n=s2.size();

    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(int j=0; j<=n ; j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i]==s2[j]){
              dp[i][j]=dp[i-1][j-1]+1;  
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[m][n];
}