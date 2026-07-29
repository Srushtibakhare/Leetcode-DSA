#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    const long long MAX_LIMIT = 1000001; // Capped to avoid integer overflow

    // Safe combination calculation: nCr capped at MAX_LIMIT
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res >= MAX_LIMIT) return MAX_LIMIT;
        }
        return res;
    }

    // Calculates total unique multiset permutations of the remaining characters
    long long countArrangements(const std::vector<int>& halfCount) {
        int total = 0;
        for (int freq : halfCount) {
            total += freq;
        }
        
        long long res = 1;
        int remaining = total;
        for (int freq : halfCount) {
            if (freq > 0) {
                res *= nCr(remaining, freq);
                if (res >= MAX_LIMIT) return MAX_LIMIT;
                remaining -= freq;
            }
        }
        return res;
    }

public:
    std::string smallestPalindrome(std::string s, int k) {
        std::vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Validate if a palindrome configuration can actually be formed
        int oddCount = 0;
        int oddCharIndex = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                oddCount++;
                oddCharIndex = i;
            }
        }
        if (oddCount > 1) return "";

        // Halve the frequencies to only build the first half
        std::vector<int> halfCount(26, 0);
        int halfLen = 0;
        for (int i = 0; i < 26; ++i) {
            halfCount[i] = count[i] / 2;
            halfLen += halfCount[i];
        }

        // Verify total arrangements are sufficient for the target index k
        long long totalPermutations = countArrangements(halfCount);
        if (totalPermutations < k) return "";

        std::string leftHalf = "";
        // Lexicographically construct the first half element by element
        for (int pos = 0; pos < halfLen; ++pos) {
            for (int i = 0; i < 26; ++i) {
                if (halfCount[i] == 0) continue;

                // Optimistically place character i
                halfCount[i]--;
                long long arrangements = countArrangements(halfCount);

                if (arrangements >= k) {
                    leftHalf += (char)(i + 'a');
                    break; // Choice locked down, move to next position
                } else {
                    k -= arrangements; // Skip this block of permutations
                    halfCount[i]++;    // Revert choice
                }
            }
        }

        // Generate the mirror image right half
        std::string rightHalf = leftHalf;
        std::reverse(rightHalf.begin(), rightHalf.end());

        // Reconstruct full string including center character if length was odd
        if (oddCharIndex != -1) {
            return leftHalf + (char)(oddCharIndex + 'a') + rightHalf;
        }
        return leftHalf + rightHalf;
    }
};

// VS Code boilerplate to run locally
int main() {
    Solution solver;
    std::cout << "Example 1: " << solver.smallestPalindrome("abba", 2) << " (Expected: baab)\n";
    std::cout << "Example 2: " << solver.smallestPalindrome("aa", 2) << " (Expected: \"\")\n";
    std::cout << "Example 3: " << solver.smallestPalindrome("bacab", 1) << " (Expected: abcba)\n";
    return 0;
}
