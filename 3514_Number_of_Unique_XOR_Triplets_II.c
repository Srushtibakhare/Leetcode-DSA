#include <stdio.h>
#include <stdbool.h>

int uniqueXorTriplets(int nums[], int n)
{
    if (n == 1)
        return 1;

    bool pair[2048] = {false};
    bool triplet[2048] = {false};

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pair[nums[i] ^ nums[j]] = true;
        }
    }

    for (int x = 0; x < 2048; x++)
    {
        if (!pair[x])
            continue;

        for (int i = 0; i < n; i++)
        {
            triplet[x ^ nums[i]] = true;
        }
    }

    int ans = 0;

    for (int i = 0; i < 2048; i++)
    {
        if (triplet[i])
            ans++;
    }

    return ans;
}

int main()
{
    int nums[] = {1, 3};

    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Answer = %d\n", uniqueXorTriplets(nums, n));

    return 0;
}