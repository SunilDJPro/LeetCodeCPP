#include <iostream>
#include <vector>
#include <numeric>
#include <functional> // for std::bit_xor

class XORGame {
public:
    bool xorGame(std::vector<int>& nums) {
        // Compute the XOR of all elements in the array
        int totalXor = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
        
        // If the XOR is already 0, Alice wins
        if (totalXor == 0) {
            return true;
        }
        
        // If the size of the array is even, Alice wins
        return nums.size() % 2 == 0;
    }
};

int main() {
   XORGame xorgame;
    
    // Test case 1
    std::vector<int> nums1 = {1, 1, 2};
    bool result1 = xorgame.xorGame(nums1);
    std::cout << "Test case 1: " << (result1 ? "Alice wins" : "Alice loses") << std::endl;

    // Test case 2
    std::vector<int> nums2 = {0, 1};
    bool result2 = xorgame.xorGame(nums2);
    std::cout << "Test case 2: " << (result2 ? "Alice wins" : "Alice loses") << std::endl;

    // Test case 3
    std::vector<int> nums3 = {1, 2, 3};
    bool result3 = xorgame.xorGame(nums3);
    std::cout << "Test case 3: " << (result3 ? "Alice wins" : "Alice loses") << std::endl;

    return 0;
}
