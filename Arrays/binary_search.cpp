/*
Problem: Binary Search
Platform: Basic Implementation
Approach: Divide and Conquer
Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = 5;
    int target = 7;

    int result = binarySearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}
