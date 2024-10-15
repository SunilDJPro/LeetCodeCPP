#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<long long> maxHeap;

        for (int num: nums) {
            maxHeap.push(num);
        }

        long long score = 0;

        for (int i = 0; i < k; ++i) {
            long long maxVal = maxHeap.top();
            maxHeap.pop();

            score += maxVal;

            long long newVal = (maxVal + 2) / 3;
            maxHeap.push(newVal);
        }

        return score;
    }
};


class Tester : public Solution {
public:
    Tester(vector<int>& nums, int k) {
        cout << "The max score is: " << maxKelements(nums, k) << endl;
    }
};

auto main() -> int {

    vector<int> nums1 =  {10,10,10,10,10};
    int k1 = 5;
    Tester test1(nums1, k1);

    vector<int> nums2 = {1,10,3,3,3};
    int k2 = 3;
    Tester test2(nums2, k2);

    return EXIT_SUCCESS;
}