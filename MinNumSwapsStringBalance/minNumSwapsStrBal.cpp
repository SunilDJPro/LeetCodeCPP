#include <iostream>
#include <string>

using  namespace std;

class Solution {
public:
    int minSwaps(string s) {
        
        return checkBalanced(s);
    }

private:
    int checkBalanced(const string& s) {

        int balance = 0, min_balance = 0;

        for (char c : s) {

            if (c == '[') {
                balance++;
            } else {
                balance--;
            }
            min_balance = min(min_balance, balance);
            cout << "The current char is: " << c << " and the min_balance is: " << min_balance <<endl;

        }

        return ((-min_balance + 1) / 2); 
    }
};

class tester : public Solution {

public:
     tester(string& s) {

        int temp = minSwaps(s);
        cout << "For the provided \"" << s << "\"  string, it takes " << temp << " to balance out." << endl;

    }
};


auto main() -> int {


    string s1 = "][][";
    tester test1(s1);

    string s2 = "]]][[[";
    tester test2(s2);

    string s3 = "[]";
    tester test3(s3);

    return 0;
}
