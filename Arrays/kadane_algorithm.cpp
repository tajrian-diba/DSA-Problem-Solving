/*
Problem: Maximum Subarray Sum (Kadane's Algorithm)
Platform: LeetCode / Interview Classic
Approach: Dynamic Programming
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <climits>
using namespace std;

int maxSubArray(int arr[], int n) {
    int maxSoFar = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        if (currentSum > maxSoFar)
            maxSoFar = currentSum;

        if (currentSum < 0)
            currentSum = 0;
    }

    return maxSoFar;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;

    cout << "Maximum Subarray Sum: " << maxSubArray(arr, n);

    return 0;
}
