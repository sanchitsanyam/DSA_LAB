#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ans;
    int n;
    cin>>n;
    for(int i=0; i<n ; i++){
        int a;
        cin>>a;
        ans.push_back(a);
    }
    while(ans.size()){
        sort(ans.begin(),ans.end());
        int t=ans[0];
        int n=ans.size();
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=ans[i];
        }
        ans.clear();
        for(int i=0;i<n;i++){
            if((arr[i]-t)>0){
                ans.push_back(arr[i]-t);
            }
        }
        cout<<ans.size()<<endl;
    }
}

Your code implements a logic resembling **reduction operations** on a list. However, the way it sorts and repeatedly processes the vector makes it **inefficient**, with a **time complexity of O(n² log n)** due to the repeated sorting operations. Let's break it down and improve the code to achieve **better efficiency**.

---

### Optimized Approach
Instead of sorting the array every time, you can:
1. **Use a frequency counter** to store how many times each element appears.
2. **Process the smallest elements first** without re-sorting the array each time.
3. Use a **`multiset`** or **min-heap** for efficiently finding and removing the smallest elements.

Here’s the optimized version:

---

### Optimized Code Using Min-Heap (O(n log n) Solution)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store elements

    // Insert all elements into the min-heap
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        minHeap.push(a);
    }

    int previous = 0; // Track the last extracted element
    while (!minHeap.empty()) {
        // Find the current smallest element and remove duplicates
        int current = minHeap.top();
        minHeap.pop();

        // Only process if the element is larger than the last processed one
        if (current > previous) {
            cout << minHeap.size() + 1 << endl; // +1 to include the current element
            previous = current; // Update the previous element
        }

        // Remove remaining occurrences of the same smallest element
        while (!minHeap.empty() && minHeap.top() == current) {
            minHeap.pop();
        }
    }

    return 0;
}
```

---

### Explanation:
1. **`priority_queue` as Min-Heap**: This data structure helps us always access the smallest element in **O(log n)** time.
2. **Skip duplicate elements**: After processing an element, we remove all occurrences of it to avoid unnecessary work.
3. **Efficiency**: Instead of sorting the entire vector repeatedly, we use a **min-heap** to efficiently retrieve the smallest element.

---

### Time Complexity:
- **Building the Min-Heap:** O(n log n).
- **Processing elements:** O(n log n) in total, since each extraction takes O(log n).
- **Overall:** O(n log n), which is a significant improvement over the original O(n² log n) solution.

---

This optimized approach ensures that the problem is solved efficiently for large inputs.
