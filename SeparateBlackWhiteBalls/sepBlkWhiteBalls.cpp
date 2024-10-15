#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    private:
        long long swaps = 0;

    public:
        long long minimumSteps(string s) {
            int n = s.size();
            vector<int> positions;

            for (int i = 0; i < n; ++i) {
                if (s[i] == '1') {
                    positions.push_back(i);
                }
            }

            int m = positions.size();

            for (int i = 0; i < m; ++i) {
                swaps += abs(positions[i] - (i + (n - m)));
            }

            return swaps;

        }
};

class Tester : public Solution {
public: 
    Tester(string& s) {
    cout << "The minimum steps to seperate white and black balls: " << minimumSteps(s) << endl;
    }
};


auto main() -> int {

    string s1 = "101";
    Tester test1(s1);

    string s2 = "100";
    Tester test2(s2);

    string s3 = "0111";
    Tester test3(s3);

    return 0;
}


