#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countAndSort(vector<int>& arr, int left, int mid, int right) {
    int inversion = 0;
    vector<int> ans(right - left + 1);

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            ans[k++] = arr[i++];
        } else {
            ans[k++] = arr[j++];
            inversion += (mid - i + 1);
        }
    }

    // copy remaining elements
    while (i <= mid) ans[k++] = arr[i++];
    while (j <= right) ans[k++] = arr[j++];

    // copy back to original array
    for (int p = left, t = 0; p <= right; p++, t++) {
        arr[p] = ans[t];
    }

    return inversion;
}

int countInversion(vector<int>& arr, int left, int right) {
    int inversion = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversion += countInversion(arr, left, mid);
        inversion += countInversion(arr, mid + 1, right);
        inversion += countAndSort(arr, left, mid, right);
    }
    return inversion;
}

int inversionCount(vector<int>& arr) {
    return countInversion(arr, 0, arr.size() - 1);
}

int main() {
    cout << "Enter the size of array:" << endl;
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the values of array:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "array is:" << endl;
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << inversionCount(arr) << endl;
}
