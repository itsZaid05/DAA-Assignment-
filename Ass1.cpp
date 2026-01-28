#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int steps = 0;

    while (low <= high) {
        steps++;
        int mid = low + (high - low) / 2;  // Avoid overflow
        
        cout << "Step " << steps << ": low=" << low << ", mid=" << mid 
             << ", high=" << high << ", arr[mid]=" << arr[mid] << endl;

        if (arr[mid] == target) {
            cout << "Found at index " << mid << endl;
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << "Not found" << endl;
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    
    cout << "Searching for " << target << " in array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    binarySearch(arr, size, target);
    
    return 0;
}
