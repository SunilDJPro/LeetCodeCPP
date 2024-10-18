#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {

        int maxOr = 0, count = 0;

        for (int num : nums) {
            maxOr |= num;
        }

        backtrack(nums, 0, 0, maxOr, count);
        return count;
    }

private:
    void backtrack(const vector<int>& nums, int index, int currentOr, int maxOr, int& count) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }

        backtrack(nums, index + 1, currentOr | nums[index], maxOr, count);

        backtrack(nums, index + 1, currentOr, maxOr, count);
    }
};

class Tester : public Solution {
public:
    Tester(vector<int>& nums) {
        cout << "The Max number of BitwiseOR subset are " << countMaxOrSubsets(nums) << endl;
    }
};

auto main() -> int {
    
    vector<int> nums1 = {3, 1};
    Tester test1(nums1);

    vector<int> nums2 = {2, 2, 2};
    Tester test2(nums2);

    vector<int> nums3 = {3, 2, 1, 5};
    Tester test3(nums3);

    return EXIT_SUCCESS;
}