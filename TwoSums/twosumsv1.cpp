#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            cout<<"\ni = "<<i<<endl; //Logging for reasoning purpose
            for (int j = i + 1; j < n; j++) {
                cout<<"j = "<<j<<endl; //Logging for reasoning purpose
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        
        return {};  // No solution found
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 1, 5, 10, 20, 15, 11, 9, 16};
    int target = 30;
    
    vector<int> result = solution.twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }
    
    return 0;
}
