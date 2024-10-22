#include <iostream>
#include <vector>
using namespace std;

double mergeAndFindMedian(const vector<int>& A, const vector<int>& B) {
    int m = A.size();
    int n = B.size();
    vector<int> merged;
    merged.reserve(m + n); // Reserve space for merged array

    int i = 0, j = 0;

    // Merge the two arrays
    while (i < m && j < n) {
        if (A[i] < B[j]) {
            merged.push_back(A[i]);
            i++;
        } else {
            merged.push_back(B[j]);
            j++;
        }
    }

    // Append remaining elements from A
    while (i < m) {
        merged.push_back(A[i]);
        i++;
    }

    // Append remaining elements from B
    while (j < n) {
        merged.push_back(B[j]);
        j++;
    }

    // Calculate the median
    int totalLength = m + n;
    if (totalLength % 2 == 0) {
        // If even, average the two middle numbers
        return (merged[totalLength / 2 - 1] + merged[totalLength / 2]) / 2.0;
    } else {
        // If odd, return the middle number
        return merged[totalLength / 2];
    }
}

int main() {
    vector<int> A = {1, 3};
    vector<int> B = {2, 4};
    double median = mergeAndFindMedian(A, B);
    cout << "Median: " << median << endl;
    return 0;
}


5. **Main Function**: 
   - In `main`, we define two sorted arrays, call the function, and print the median.

### Complexity
- **Time Complexity**: \(O(m + n)\) due to the merging process.
- **Space Complexity**: \(O(m + n)\) for storing the merged array.

This implementation is straightforward and efficient for situations where you want both the merged array and the median. If you're only interested in the median, you might want to consider the binary search method for better performance.
