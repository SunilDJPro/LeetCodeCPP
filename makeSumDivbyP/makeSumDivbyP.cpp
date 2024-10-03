#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0; //64bit integer 
        
        for (int num : nums) {
            totalSum += num;
        }

        int targetMod = totalSum % p; //Target remainder to check with divisibility
        if (targetMod == 0) {
            return 0; //Already divisible by P
        }

        unordered_map<int , int> modMap; //Stores prefix mod with its last index
        modMap[0] = -1;
        long long prefixSum = 0;
        int minLength = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            int currentMod = prefixSum % p;
            int neededMod = (currentMod - targetMod + p) % p;

            if (modMap.find(neededMod) != modMap.end()) {
                minLength = min(minLength, i - modMap[neededMod]);
            }

        modMap[currentMod] = i; //Stores the last index of the current Mod
           
        }

    return (minLength == nums.size()) ? -1 : minLength;
    
    }
};

auto tester(vector<int>& nums, int p) -> void {

    Solution soln;

    cout << "Target divisility Modulo is: " << p <<endl;
    cout << "Size of the array is: " << nums.size() << endl;
    cout << "Elements of the array are: ";
    for_each(nums.begin(), nums.end(), [](int x){cout << x << " ";});

    cout << endl;

    cout << "Length of the smallest subarray is: " << soln.minSubarray(nums, p) << endl;
    cout << "\n" << endl;
} 


auto main() -> int {

    //Test Case 1
    vector<int> arr1 = {3, 1, 4, 2};
    int p1 = 6;
    tester(arr1, p1);

    //Test Case 2
    vector<int> arr2 = {6, 3, 5, 2};
    int p2 = 9;
    tester(arr2, p2);

    //Test Case 3
    vector<int> arr3 = {1, 2, 3};
    int p3 = 3;
    tester(arr3, p3);

    //Test Case 4
    vector<int> arr4 = {5, 10};
    int p4 = 6;
    tester(arr4, p4);

    return 0;
}