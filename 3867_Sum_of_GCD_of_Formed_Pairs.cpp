#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long gcdSum(vector<int>& nums)
{
    int n = nums.size();
    vector<int> prefixGcd(n);

    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        mx = max(mx, nums[i]);
        prefixGcd[i] = gcd(nums[i], mx);
    }

    sort(prefixGcd.begin(), prefixGcd.end());

    long long ans = 0;

    for (int i = 0; i < n / 2; i++)
    {
        ans += gcd(prefixGcd[i], prefixGcd[n - i - 1]);
    }

    return ans;
}

int main()
{
    vector<int> nums = {3, 6, 2, 8};

    cout << gcdSum(nums) << endl;

    return 0;
}