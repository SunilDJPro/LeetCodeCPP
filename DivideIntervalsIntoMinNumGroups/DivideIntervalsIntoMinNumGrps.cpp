#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            if (!pq.empty() && pq.top() < start) {
                pq.pop();
            }

            pq.push(end);
        }

        return pq.size();
    }
};

class Tester : public Solution {
public:
    Tester(vector<vector<int>>& intervals) {

        cout << "The Intervals can be divided into " << minGroups(intervals) << " Groups!" << endl;
    }
};

auto main() -> int {

    vector<vector<int>> int1 = {{5,10}, {6,8}, {1,5}, {2,3}, {1,10}};
    Tester test1(int1);

    vector<vector<int>> int2 = {{1,3}, {5,6}, {8,10}, {11,13}};
    Tester test2(int2);

    return EXIT_SUCCESS;

}