#include <iostream>
#include <vector>
using namespace std;
// FUNCTION PARTITION(A, st, end)
// Input:
// An array A with indices st (start) and end (end).
// Output:
// Correct position of an element.

// pivot ← A[end]
// idx ← st − 1
// FOR i ← st TO end − 1 DO
//        IF A[i] ≥ pivot THEN
//             idx ← idx + 1
//             swap(A[idx], A[i])
//        END IF
//    END FOR
// idx ← idx + 1
// swap(A[idx], A[end])
// RETURN idx


//Time Complexity:
// Best Case → O(n)
// Average Case → O(n)
// Worst Case → O(n)

//Space Complexity: O(1)
int partition (vector<int> &nums, int st, int end) {
    int pivot = nums[end];
    int idx = st-1;
    for (int i= st; i<end; i++) {
        if (nums[i] >=pivot){
            idx++;
            swap(nums[idx], nums[i]);
        }
    }

    idx++;
    swap(nums[idx], nums[end]);
    return idx;
}

// FUNCTION QUICK(A, st, end)
// Input:
// An array A with indices st (start) and end (end).
// Output:
// Array A sorted in descending order.

// IF st < end THEN
//        pivotIndex ← PARTITION(A, st, end)
//        QUICK(A, st, pivotIndex − 1)
//        QUICK(A, pivotIndex + 1, end)
//    END IF

// END

// Time Complexity:
// Best Case → O(n log n)
// Average Case → O(n log n)
// Worst Case → O(n²)

//Space Complexity:
// Best/Avg Case: O(log n)
// Worst Case: O(n)
void Quick(vector<int> &nums, int st, int end) {
    if (st<end) {
        int pivot = partition(nums,st, end);
        Quick(nums, st, pivot-1);
        Quick(nums, pivot+1, end);
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    int num;
    cout << "Enter elements in array: ";
    for (int i=0; i<n; i++) {
        cin >> num;
        nums[i] = num;
    }
    cout << endl;
    Quick(nums, 0, nums.size()-1);
    for (int i: nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}