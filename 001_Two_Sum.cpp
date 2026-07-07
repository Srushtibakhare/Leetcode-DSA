/*
-------------------------------------------------------
LeetCode #1 - Two Sum
Difficulty : Easy
Language   : C++

Concepts:
- Arrays
- Brute Force
- Nested Loops

Time Complexity : O(n²)
Space Complexity: O(1)
-------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            if(nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }

    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "Indices: ";

    for(int index : result)
    {
        cout << index << " ";
    }

    cout << endl;

    return 0;
}