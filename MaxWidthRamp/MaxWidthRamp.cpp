#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> stack;
        int n = nums.size();

        for(int i = 0; i < n; ++i) { //Numerate the stack with potential ramp
            if (stack.empty() || nums[stack.top()] > nums[i]) {
                stack.push(i);
            }
        }
        //cout << "Current top of the stack: " << stack.top() << endl;
        int maxWidth = 0;

        for (int j = n - 1; j >= 0; --j) { //Traverse from the end to find the Max width
            while (!stack.empty() && nums[stack.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - stack.top());
                stack.pop();
            }
        }

        return maxWidth;
    }
    
};


class Tester : public Solution {
public:
    Tester(vector<int>& nums) {

        cout << "The provided array of nums are: ";
        for_each(nums.begin(), nums.end(), [](int n) {cout << n <<" ";});
        cout << endl;
        cout << "The maximum width of the ramp is: " << maxWidthRamp(nums) << endl;
        cout << endl;
    } 
};


auto main() -> int {
    
    vector<int> nums1 = {6, 0, 8, 2, 1, 5};
    Tester test1(nums1);

    vector<int> nums2 = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    Tester test2(nums2);

    return 0;
}
