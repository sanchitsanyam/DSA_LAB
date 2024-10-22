#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    sort(arr.begin(),arr.end());
    if(n%2==0){
        cout<<(arr[n/2]+arr[(n/2) +1])/2<<endl;
    }
    else{
        cout<<arr[(n/2)+1]<<endl;
    }
}
Here’s how you can implement **finding the median of an unsorted array** in **C++** using both **sorting** and the **Quickselect algorithm**.

---

### **1. Naive Approach (Sorting the Array)**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>  // For sort

using namespace std;

double findMedianSort(vector<int>& arr) {
    sort(arr.begin(), arr.end());  // Sort the array
    int n = arr.size();

    if (n % 2 == 1) {
        return arr[n / 2];  // If odd, return the middle element
    } else {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;  // If even, return average of two middle elements
    }
}

int main() {
    vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};
    cout << "Median: " << findMedianSort(arr) << endl;  // Output: 4.5
    return 0;
}
```

**Explanation:**
- This code sorts the array in \(O(N \log N)\) time and finds the median based on whether the size is even or odd.

---

### **2. Optimized Approach (Quickselect Algorithm)**

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = low;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);  // Place the pivot in its correct position
    return i;
}

int quickselect(vector<int>& arr, int low, int high, int k) {
    if (low == high) return arr[low];  // If the list contains only one element

    int pivotIndex = partition(arr, low, high);

    if (pivotIndex == k) {
        return arr[pivotIndex];  // Found the k-th smallest element
    } else if (pivotIndex < k) {
        return quickselect(arr, pivotIndex + 1, high, k);
    } else {
        return quickselect(arr, low, pivotIndex - 1, k);
    }
}

double findMedian(vector<int>& arr) {
    int n = arr.size();
    if (n % 2 == 1) {
        return quickselect(arr, 0, n - 1, n / 2);  // Odd size
    } else {
        int mid1 = quickselect(arr, 0, n - 1, n / 2 - 1);
        int mid2 = quickselect(arr, 0, n - 1, n / 2);
        return (mid1 + mid2) / 2.0;  // Even size
    }
}

int main() {
    vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};
    srand(time(0));  // Seed for randomization (optional)
    cout << "Median: " << findMedian(arr) << endl;  // Output: 4.5
    return 0;
}
```

---

### **Explanation of Quickselect Approach**

1. **Partition Function:**  
   Rearranges the elements such that elements smaller than the pivot are on the left, and elements larger than the pivot are on the right.

2. **Quickselect Function:**  
   It recursively narrows down the search to find the k-th smallest element.

3. **Median Function:**  
   - If the size is odd, the median is the middle element.
   - If the size is even, the median is the average of the two middle elements.

---

### **Time Complexity**

- **Naive Approach:** \(O(N \log N)\) due to sorting.
- **Quickselect Approach:** \(O(N)\) on average, \(O(N^2)\) in the worst case.

---

This C++ implementation ensures **optimal performance** with large arrays when the Quickselect algorithm is used.
