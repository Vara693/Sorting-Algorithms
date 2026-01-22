#include <iostream>
#include <vector>
using namespace std;

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

void merge_sort(vector<int> &nums, int st, int end) {
    if (st<end) {
        int mid = st + (end-st)/2;
        merge_sort(nums, st, mid);
        merge_sort(nums, mid+1, end);
        merge(nums, st, mid, end);
    }
}

int main() {
    vector <int> ans = {23, 1, 78, 0, 52, 7, 91, 1000};
    merge_sort(ans, 0, ans.size()-1);
    for (int i: ans) {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}