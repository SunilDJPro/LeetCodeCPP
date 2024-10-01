#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainder_count;

    //Calculate frequency of each remainder
    for (int num : arr) {
        int remainder = num % k;
        if (remainder < 0) {
            remainder += k;  //Handle negative numbers
        }
        remainder_count[remainder]++;
    }

    //Check conditions for valid pairing
    for (auto& entry : remainder_count) {
        int remainder = entry.first;
        int count = entry.second;

        if (remainder == 0) {
            //Elements divisible by k must have an even count
            if (count % 2 != 0) {
                return false;
            }
        } else {
            //Elements with remainder 'r' must have equal count with remainder 'k - r'
            int complement = k - remainder;
            if (remainder_count[complement] != count) {
                return false;
            }
        }
    }

    return true;

    }
};


auto main() -> int { //Test cases

    Solution solution;

    vector<int> arr1 = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    int k1 = 5;
    cout << (solution.canArrange(arr1, k1) ? "True" : "False") << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    int k2 = 7;
    cout << (solution.canArrange(arr2, k2) ? "True" : "False") << endl;

    vector<int> arr3 = {1, 2, 3, 4, 5, 6};
    int k3 = 10;
    cout << (solution.canArrange(arr3, k3) ? "True" : "False") << endl;

    return 0;

}