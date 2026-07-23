class Solution:
    def shortcutXorTriplets(self, nums: list[int]) -> int:
        n = len(nums)
        
        # Agar array ka size 1 ya 2 hai, toh limited unique XOR values banengi
        if n <= 2:
            return n
            
        # Agar n >= 3 hai, toh bitwise combinations se 0 se lekar (2^bit_length - 1) 
        # tak ki saari values banayi ja sakti hain.
        # Iska total count hoga: 2 ^ (n ki bit length)
        return 1 << n.bit_length()

# --- VS Code Me Local Test Karne Ke Liye Runner ---
if __name__ == "__main__":
    solver = Solution()
    
    # Test Case 1: nums = [1, 2] (n = 2)
    test_1 = [1, 2]
    print(f"Test 1 Input: {test_1} -> Output: {solver.shortcutXorTriplets(test_1)}")  # Expected: 2
    
    # Test Case 2: nums = [3, 1, 2] (n = 3)
    test_2 = [3, 1, 2]
    print(f"Test 2 Input: {test_2} -> Output: {solver.shortcutXorTriplets(test_2)}")  # Expected: 4
