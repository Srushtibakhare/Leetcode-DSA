#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxActiveSectionsAfterTrade(vector<int>& nums)
{
    int left = 0;
    int zeros = 0;
    int ans = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] == 0)
            zeros++;

        while (zeros > 1)
        {
            if (nums[left] == 0)
                zeros--;

            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,1,0,1,1,0,1};

    cout << "Maximum Active Sections = "
         << maxActiveSectionsAfterTrade(nums)
         << endl;

    return 0;
}