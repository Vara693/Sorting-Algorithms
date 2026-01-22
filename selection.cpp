#include <iostream>
using namespace std;

void Selection(int* arr, int n) {
    for (int i = 0; i<n-1; i++) {
        int sindex = i;
        for (int j = i+1; j<n; j++) {
            if (arr[j] < arr[sindex]) {
                sindex = j;
            }
        }
        swap(arr[i], arr[sindex]);
    }
}

void Insertion(int* arr, int n) {
    for (int i = 1; i<n; i++) {
        int curr = arr[i];
        int prev = i-1;

        while (prev>=0 && arr[prev] > curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;
    }
}

void mergeSort(int* arr, int st, int end) {
    if (st< end) {
        int mid = st + (end-st)/2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid+1, end);
        // merge(arr, st, mid, end);
    }
}

// void merge(int* arr, int st, int mid, int end) {
//     int temp[end-st+1];
//     int i = st;
//     int j = mid;

//     while (i<=j && j<=end) {
//         if (arr[i]<=arr[j]) {
            
//         }
//     }
// }

int partition(int* arr, int st, int end) {
    // int pivot = arr[end];
    // int pvtidx = st-1;

    // for (int i= st; i<end; i++) {
    //     if (arr[i] <= pivot) {
    //         pvtidx++;
    //         swap(arr[i], arr[pvtidx]);
    //     }
    // }

    // pvtidx++;
    // swap(arr[pvtidx], arr[end]);
    // return pvtidx;

    int pivot = arr[st];
    int pvtidx = st;

    for (int i = st+1; i<=end; i++) {
        if (arr[i] <= pivot) {
            pvtidx++;
            swap(arr[i], arr[pvtidx]);
        }
    }

    swap(arr[pvtidx], arr[st]);
    return pvtidx;
}

void QuickSort (int* arr, int st, int end) {
    if (st<end) {
        int pvt = partition(arr, st, end);
        QuickSort(arr, st, pvt-1);
        QuickSort(arr, pvt+1, end);
    }
}
int main() {
    int arr[] = {64, 25, 12, 22, 11, 30, 30, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr,0, n-1);

    for (int val: arr) {
        cout << val << " ";
    }

    return 0;
}