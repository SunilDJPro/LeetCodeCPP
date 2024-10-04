#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <tuple> //Requires C++17
//#include <format> //Requires C++17


using namespace std;

class Solution {

public:
    long long dividePlayers(vector<int>& skill) {

        sort(skill.begin(), skill.end());

        int n = skill.size();
        long long totalChemistry = 0;
        int totalSkill = skill[0] + skill[n - 1];
        unordered_map<int, std::tuple<int, int>> Pairs;
        cout << "The total Skill value for the team is: " << totalSkill <<endl;

        for (int i = 0; i < n / 2; ++i) {
            if (skill[i] + skill[n - i - 1] != totalSkill) {
                return -1; //Cant form an equal skilled team if != totalSkill in any pair
            }

            Pairs[i] = {skill[i], skill[n - i -1]};
            totalChemistry += 1LL * skill[i] * skill[n - i -1];

        }
        cout << "The plausible pairs for the given players are: ";
        for (int i = 0; i < Pairs.size(); ++i) {
            auto [x, y] = Pairs[i];
            cout << "(" << x << ", " << y << ")";
            cout << " ";
        }
        cout << "." << endl;

        return totalChemistry;

    }
};

auto main() -> int {

    Solution soln;

    vector<int> skill1 = {3, 2, 5, 1, 3, 4};
    cout << soln.dividePlayers(skill1) << endl; 

    vector<int> skill2 = {3, 4};
    cout << soln.dividePlayers(skill2) << endl; 

    vector<int> skill3 = {1, 1, 2, 3};
    cout << soln.dividePlayers(skill3) << endl;

}