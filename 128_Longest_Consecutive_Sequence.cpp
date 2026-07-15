#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int>& nums)
{
    unordered_set<int> numSet(nums.begin(), nums.end());

    int longest = 0;

    for (int num : numSet)
    {
        if (numSet.find(num - 1) == numSet.end())
        {
            int current = num;
            int streak = 1;

            while (numSet.find(current + 1) != numSet.end())
            {
                current++;
                streak++;
            }

            longest = max(longest, streak);
        }
    }

    return longest;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << "Longest Consecutive Sequence Length: "
         << longestConsecutive(nums) << endl;

    return 0;
}
