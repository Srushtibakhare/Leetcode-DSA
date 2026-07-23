#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        // Map to store frequency of prefix sums
        std::unordered_map<int, int> prefixSumMap;
        
        // Base case: A prefix sum of 0 has occurred 1 time (empty subarray)
        prefixSumMap[0] = 1;
        
        int currentSum = 0;
        int count = 0;
        
        for (int num : nums) {
            // Update the running prefix sum
            currentSum += num;
            
            // Check if (currentSum - k) exists in the map
            int target = currentSum - k;
            if (prefixSumMap.find(target) != prefixSumMap.end()) {
                count += prefixSumMap[target];
            }
            
            // Store/increment the current prefix sum frequency
            prefixSumMap[currentSum]++;
        }
        
        return count;
    }
};

// Boilerplate main function for local debugging in VS Code
int main() {
    Solution solver;
    
    // Example 1
    std::vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    std::cout << "Example 1 Output: " << solver.subarraySum(nums1, k1) << " (Expected: 2)" << std::endl;

    // Example 2
    std::vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    std::cout << "Example 2 Output: " << solver.subarraySum(nums2, k2) << " (Expected: 2)" << std::endl;

    return 0;
}
