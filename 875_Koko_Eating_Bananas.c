#include <stdio.h>

int minEatingSpeed(int* piles, int pilesSize, int h) {

    int left = 1;
    int right = 0;

    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right)
            right = piles[i];
    }

    int ans = right;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        long long hours = 0;

        for (int i = 0; i < pilesSize; i++) {
            hours += (piles[i] + mid - 1) / mid;
        }

        if (hours <= h) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {

    int piles1[] = {3, 6, 7, 11};
    printf("%d\n", minEatingSpeed(piles1, 4, 8));

    int piles2[] = {30, 11, 23, 4, 20};
    printf("%d\n", minEatingSpeed(piles2, 5, 5));

    int piles3[] = {30, 11, 23, 4, 20};
    printf("%d\n", minEatingSpeed(piles3, 5, 6));

    return 0;
}