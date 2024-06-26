#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        
        for (int i = 0; i < nums.size(); i++) {
            cout<<"\ni= "<<i<<endl;
            int complement = target - nums[i];
            cout<<"complement= "<<complement<<endl;
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
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
