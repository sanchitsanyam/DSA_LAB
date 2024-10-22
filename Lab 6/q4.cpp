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


Sure! Here’s the C++ code with the `using namespace std;` directive included. This makes the code cleaner by allowing you to omit the `std::` prefix for standard library types and functions.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string multiplyBinaryStrings(const string& a, const string& b) {
    if (a == "0" || b == "0") return "0";  // Early return for zero multiplication

    int n = a.size();
    int m = b.size();
    vector<int> result(n + m, 0);  // To store the multiplication result

    // Reverse both strings to make indexing easier
    string A = string(a.rbegin(), a.rend());
    string B = string(b.rbegin(), b.rend());

    // Multiply each digit and accumulate the results
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int product = (A[i] - '0') * (B[j] - '0');  // Multiply individual bits
            result[i + j] += product;  // Add to the correct position

            // Handle carry
            if (result[i + j] >= 2) {
                result[i + j + 1] += result[i + j] / 2;  // Carry to the next digit
                result[i + j] %= 2;  // Keep only the binary digit (0 or 1)
            }
        }
    }

    // Convert the result vector back to a binary string
    string res;
    for (int i = result.size() - 1; i >= 0; --i) {
        res += (result[i] + '0');  // Convert each integer back to a char
    }

    // Remove leading zeros
    size_t pos = res.find_first_not_of('0');
    return pos == string::npos ? "0" : res.substr(pos);
}

int main() {
    string bin_str1 = "101";  // 5 in decimal
    string bin_str2 = "11";   // 3 in decimal
    string result = multiplyBinaryStrings(bin_str1, bin_str2);
    cout << result << endl;  // Output: "1111" (15 in decimal)
    return 0;
}
```

### Key Changes:
- The directive `using namespace std;` is included after the `#include` statements, so you can use standard library features without the `std::` prefix.
- The rest of the code remains unchanged, maintaining the logic for multiplying two binary strings efficiently.

### Compilation and Execution:
You can compile this code using a C++ compiler (like `g++`) and run the resulting executable to see the output. For example:

```sh
g++ -o multiply_binary multiply_binary.cpp
./multiply_binary
```

This will print the result of multiplying the two binary strings. Let me know if you need any further help!
