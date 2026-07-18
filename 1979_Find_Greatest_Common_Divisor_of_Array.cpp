#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int findGCD(vector<int>& nums)
{
    int minimum = *min_element(nums.begin(), nums.end());
    int maximum = *max_element(nums.begin(), nums.end());

    return gcd(minimum, maximum);
}

int main()
{
    vector<int> nums = {2, 5, 6, 9, 10};

    cout << "GCD = " << findGCD(nums) << endl;

    return 0;
}