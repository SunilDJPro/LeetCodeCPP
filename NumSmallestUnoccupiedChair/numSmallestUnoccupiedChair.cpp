#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n = times.size();
        vector<pair<int, int>> events;

        for (int i = 0; i < n; i++) {
            events.push_back({times[i][0], i}); //arrival time
            events.push_back({times[i][1], ~i}); //depart time, using bitwise complement fot leaving
        }

        sort(events.begin(), events.end()); //sort events by time

        priority_queue<int, vector<int>, greater<int>> freeChairs; // min-heap for smallest avail chairs

        for (int i = 0; i < n; i++) {
            freeChairs.push(i);
        }

        vector<int> occupiedChair(n, -1);

        for (auto& event : events) {
            int time = event.first;
            int friendID = event.second;

            if (friendID >= 0) {
                int chair = freeChairs.top();
                freeChairs.pop();
                occupiedChair[friendID] = chair;

                if (friendID == targetFriend) {
                    return chair;
                }

            } else {
                friendID = ~friendID;
                freeChairs.push(occupiedChair[friendID]);
            }
        }

        return -1;
        
    }
};


class Tester : public Solution {
public:
    Tester(vector<vector<int>>& times, int targetFriend) {
        cout << "Number of the Unoccupied chair: " << smallestChair(times, targetFriend) <<  endl;
    }

};

auto main() -> int {

    vector<vector<int>> times1 = {{1, 4}, {2, 3}, {4, 6}};
    int targetFriend1 = 1;
    Tester test_case_1(times1, targetFriend1);

    vector<vector<int>> times2 = {{3, 10}, {1, 5}, {2, 6}};
    int targetFriend2 = 0;
    Tester test_case2(times2, targetFriend2);

    return 0;
}