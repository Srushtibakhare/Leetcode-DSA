/*
-------------------------------------------------------
LeetCode #26 - Remove Duplicates from Sorted Array
Difficulty : Easy
Language   : C++

Concepts:
- Arrays
- Two Pointers
- In-place Array Modification

Time Complexity : O(n)
Space Complexity: O(1)
-------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if(nums.empty())
        return 0;

    int i = 0;

    for(int j = 1; j < nums.size(); j++)
    {
        if(nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int k = removeDuplicates(nums);

    cout << "Unique Count: " << k << endl;

    cout << "Array: ";

    for(int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}