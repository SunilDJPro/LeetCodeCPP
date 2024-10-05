#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s2.length(), m = s1.length();

        if (m > n) return false;

        vector<int> s1_freq(26, 0), window_freq(26, 0); //Each arr size of 26 to represent 26 alphabets (a-z)

        for (char c : s1) {
            s1_freq[c - 'a']++; //subtracts c -> s1 to be windowed to check continuous permutation from the 'a' to evaluate the distance between the alphabet in c var from the ASCII val of alphabet 'a'. (ASCII=97)
        }

        for (int i = 0; i < m; i++) {
            window_freq[s2[i] - 'a']++; //Same but with the long string of alphabets to be tested
        }

        if (s1_freq == window_freq) { //Checks if the first window = permutation of s1 exactly
            return true; 
        }

        for (int i =  m; i < n; i++) {
            window_freq[s2[i] - 'a']++; //add new char from right side of the window (numeric)

            window_freq[s2[i - m] - 'a']--;  //remove old char from left

            if (s1_freq == window_freq) { //check window with the s1_freq elements
                return true;
            }
        }

        return false;
        
    }
};


auto tester(string& s1, string& s2) -> void {


    Solution soln;
    cout << (soln.checkInclusion(s1, s2) ? "true" : "false") << endl;
    
}

auto  main() -> int {

    string s1 = "ab", s2 = "eidbaoo";
    tester(s1, s2);

    s1 = "ab", s2 = "eidboaoo";
    tester(s1, s2);

    s1 = "miya", s2 = "hellomiyacya";
    tester(s1, s2);

    return 0;
}