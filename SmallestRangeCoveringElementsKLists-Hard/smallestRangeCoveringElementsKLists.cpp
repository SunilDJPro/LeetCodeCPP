#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int maxVal = INT_MIN; //32bit Lowest integer ~ -2x10^9

        for (int i = 0; i < nums.size(); i++) { //Init the heap with the first element from each list and set maxVal according to the max value among the list.
            minHeap.push({nums[i][0], i, 0});
            maxVal = max(maxVal, nums[i][0]);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;

        while(!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();

            int minVal = curr[0];
            int listIdx = curr[1];
            int elemIdx = curr[2];

            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            if (elemIdx + 1 < nums[listIdx].size()) {
                int nextVal = nums[listIdx][elemIdx + 1];
                minHeap.push({nextVal, listIdx, elemIdx + 1});
                maxVal = max(maxVal, nextVal);
            } else {
                break; //TEMP, One of the lists completed
            }


        }

        return {rangeStart, rangeEnd};
    }
};

class Tester : public Solution {
public:
    Tester(vector<vector<int>>& nums) {
        vector<int> soln = smallestRange(nums);
        cout << "The smallest Range for the given lists are: " << soln[0] << ", " << soln[1] << endl;
    }
};

auto main() -> int {

    vector<vector<int>> nums1 = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    Tester test1(nums1);

    vector<vector<int>> nums2 = {{1,2,3},{1,2,3},{1,2,3}};
    Tester test2(nums2);

    return EXIT_SUCCESS;

}
