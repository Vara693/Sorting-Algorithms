#include <iostream>
#include <vector>
using namespace std;

// FUNCTION MERGE(A, st, mid, end)

// INPUT:
// A → array of integers
// st   → starting index
// mid  → middle index
// end  → ending index

// OUTPUT:
// Merged sorted subarray stored back in A from index st to end

// Create empty array ans
// i ← st
// j ← mid + 1

// WHILE i ≤ mid AND j ≤ end DO
//     IF A[i] ≤ A[j] THEN
//         append A[i] to ans
//         i ← i + 1
//     ELSE
//         append A[j] to ans
//         j ← j + 1
//     END IF
// END WHILE

// WHILE i ≤ mid DO
//     append A[i] to ans
//     i ← i + 1
// END WHILE

// WHILE j ≤ end DO
//     append A[j] to ans
//     j ← j + 1
// END WHILE

// FOR k ← 0 TO size(ans) − 1 DO
//     A[st + k] ← ans[k]
// END FOR

// END FUNCTION

//Time Complexity: O(n)
//Space Complexity: O(n)
void merge(vector<int> &nums, int st, int mid, int end) {
    vector<int> ans;
    int i= st, j=mid+1;

    while (i<=mid && j<=end) {
        if (nums[i] <= nums[j]) {
            ans.push_back(nums[i]);
            i++;
        } else {
            ans.push_back(nums[j]);
            j++;
        }
    }

    while (i<=mid) {
        ans.push_back(nums[i]);
        i++;
    }

    while (j<=end) {
        ans.push_back(nums[j]);
        j++;
    }

    for (int i=0; i<ans.size(); i++) {
        nums[st+i] = ans[i];
    }
}


// FUNCTION MERGE_SORT(A, st, end)

// INPUT:
// A → array of integers
// st   → starting index
// end  → ending index

// OUTPUT:
// Sorted array A in ascending order

// IF st < end THEN
//     mid ← st + (end − st) / 2
//     MERGE_SORT(A, st, mid)
//     MERGE_SORT(A, mid + 1, end)
//     MERGE(A, st, mid, end)
// END IF

// END FUNCTION

// Time Complexity:
// Best Case → O(n log n)
// Average Case → O(n log n)
// Worst Case → O(n log n)

//Space Complexity: O(n)
void merge_sort(vector<int> &nums, int st, int end) {
    if (st<end) {
        int mid = st + (end-st)/2;
        merge_sort(nums, st, mid);
        merge_sort(nums, mid+1, end);
        merge(nums, st, mid, end);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> ans(n);
    cout << "Enter elements in array: ";
    int num;
    for (int i=0; i<n; i++) {
        cin >> num;
        ans[i] = num;
    }
    cout << endl;
    merge_sort(ans, 0, ans.size()-1);
    for (int i: ans) {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}