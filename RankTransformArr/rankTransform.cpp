#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> arrayRankTransform(vector<int>& arr) {
            
            vector<int> sortedArr = arr;

            sort(sortedArr.begin(), sortedArr.end());
            sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());
            
            unordered_map<int, int> rankMap;

            for (int i = 0; i < sortedArr.size(); ++i) {
                rankMap[sortedArr[i]] = i + 1;
            }

            for (int& num : arr) {
                num = rankMap[num];
            }

            return arr;
         }
};

auto tester(vector<int>& testArr) -> void {
    Solution solution;
    cout << "The Elements of the Array are: ";
    for_each(testArr.begin(), testArr.end(), [](int x){cout << x << " ";}); //Uses std::for_each to iterate over each element in an array
    cout << endl;
    
    vector<int> resArr = solution.arrayRankTransform(testArr);
    
    cout << "The rank of the given array are:  ";
    for_each(resArr.begin(), resArr.end(), [](int x){cout << x << " ";});
    cout<< " \n\n " << endl;
}

auto main() -> int {

        //Test Case 1
        vector<int> arr1 = {40, 10, 20, 30};
        tester(arr1);

        //Test Case 2
        vector<int> arr2 = {100, 100, 100};
        tester(arr2);

        //Test Case 3
        vector<int> arr3 = {37, 12, 28, 9, 100, 56, 80, 5, 12};
        tester(arr3);
}