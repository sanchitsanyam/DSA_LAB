#include<bits/stdc++.h>
using namespace std;
int decimal(string s1){
    int n=s1.size();
    int ans=0;
    int j=1;
    for(int i=0;i<n;i++){
        ans+=(s1[n-i-1]-'0')*j;
        j=j*2;
    }
    return ans;
}
int binary(int n){
    int x=0;
    int t=1;
    while(n>0){
        int k=n % 2;
        x=x+k*t;
        t=t*10;
        n=n/2;
    }
    int ans
}
int main()
{
    string s1 ,s2;
    cin>>s1>>s2;
    int x=decimal(s1);
    int y=decimal(s2);
    string xS=to_string(x);
    string yS=to_string(y);
    int n=max(xS.size(),yS.size());
    int a=stoi(xS.substr(0,2));
    int b=stoi(xS.substr(2,xS.size()));
    int c=stoi(yS.substr(0,2));
    int d=stoi(yS.substr(2,yS.size()));
    int p=(a+b)*(c+d);
    int l=a*c,m=b*d;
    int product=pow(10,n)*(l)+pow(10,n/2)*(p-l-m)+m;
    cout<<product<<endl;
    int  mq=binary(product);
    cout<<mq<<endl;
    

    

}
// 10011010010->1234
// 1011000101110->5678