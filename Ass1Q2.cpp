#include <iostream>
using namespace std;

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int idx = left; idx <= right; idx++) {
        arr[idx] = temp[idx];
    }
}

void mergeSort(int arr[], int temp[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

void printArray(int arr[], int size, const char* label) {
    cout << label;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int temp1[size1];
    
    cout << "Original arr1: ";
    printArray(arr1, size1, "");
    mergeSort(arr1, temp1, 0, size1 - 1);
    cout << "Sorted arr1: ";
    printArray(arr1, size1, "");
    
    cout << endl;
    
    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int temp2[size2];
    
    cout << "Original arr2: ";
    printArray(arr2, size2, "");
    mergeSort(arr2, temp2, 0, size2 - 1);
    cout << "Sorted arr2: ";
    printArray(arr2, size2, "");
    
    return 0;
}
