#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D'))) {
                st.pop(); // If the st.top and the c value holds A and B or C and D, pop it of the stack!
            }
            else {
                st.push(c);
            }

            
        }
        return st.size();
    }
};


auto tester(string& s) -> void {

    Solution soln;

    cout << "Minimum Length for \"" << s << "\": " << soln.minLength(s) << endl;
    
}

auto main() -> int {

    string s1 = "ABFCACDB";
    string s2 = "ACBBD";

    tester(s1);
    tester(s2);

    return 0;
}