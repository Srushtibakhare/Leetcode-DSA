#include <stdio.h>

int maxProduct(int nums[], int n) {

    int largest = 0;
    int secondLargest = 0;

    for (int i = 0; i < n; i++) {

        if (nums[i] > largest) {
            secondLargest = largest;
            largest = nums[i];
        }
        else if (nums[i] > secondLargest) {
            secondLargest = nums[i];
        }
    }

    return (largest - 1) * (secondLargest - 1);
}

int main() {

    int nums[] = {3, 4, 5, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Maximum Product = %d\n", maxProduct(nums, n));

    return 0;
}