#include <iostream>
#include <vector>
using namespace std;
int partition (vector<int> &nums, int st, int end) {
    int pivot = nums[end];
    int idx = st-1;
    for (int i= st; i<end; i++) {
        if (nums[i] <=pivot){
            idx++;
            swap(nums[idx], nums[i]);
        }
    }

    idx++;
    swap(nums[idx], nums[end]);
    return idx;
}

void Quick(vector<int> &nums, int st, int end) {
    if (st<end) {
        int pivot = partition(nums,st, end);
        Quick(nums, st, pivot-1);
        Quick(nums, pivot+1, end);
    }
}
int main() {
    vector<int> nums = {12, 3, 56, 7, 20, 89, 1, 10};
    Quick(nums, 0, nums.size()-1);
    for (int i: nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}