//Implementation for MergeSort
/**
 * Algorithm: Merge Sort (Divide and Conquer)
 * Description: Sorts an array by recursively dividing it into halves, 
 * sorting the halves and then merging them back together.
 * * Time Complexity: 
 * - Best Case:   O(n log n)
 * - Worst Case:  O(n log n)
 * - Average:     O(n log n)
 * Space Complexity: O(n) (Requires extra space for temporary arrays)
 /*
 * ============================================================================
 * REAL-WORLD & ALGORITHMIC APPLICATIONS OF DIVIDE & CONQUER (MERGE SORT)
 * ============================================================================
 * * 1. External Sorting       // Sorting massive datasets that exceed RAM capacity.
 * 2. Parallel Processing    // Splitting tasks across multi-core CPUs/cloud nodes.
 * 3. Linked Lists           // The optimal O(n log n) sort for linked structures.
 * 4. Counting Inversions    // O(n log n) trick for competitive programming.
 * 5. CDQ Divide & Conquer   // Advanced technique for offline query processing.
 * 6. Merge Joins (DBMS)     // Efficiently combining large database tables.
 * * ============================================================================
 */
 */

#include <iostream>
#include <vector>

using namespace std;

// Merges two sub-arrays of arr[].
// First sub-array is arr[left..mid]
// Second sub-array is arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp vectors back into arr[left..right]
    int i = 0;     // Initial index of first sub-array
    int j = 0;     // Initial index of second sub-array
    int k = left;  // Initial index of merged sub-array

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// The main function that sorts arr[left..right] using merge()
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return; // Base case: 1 or 0 elements
    }

    // Find the midpoint to divide the array
    int mid = left + (right - left) / 2;

    // Recursively sort first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

// Utility function to print the vector
void printVector(const vector<int>& arr) {
    for (int num: arr) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    // Test case
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: \n";
    printVector(arr);

    // Perform Merge Sort
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: \n";
    printVector(arr);

    return 0;
}
