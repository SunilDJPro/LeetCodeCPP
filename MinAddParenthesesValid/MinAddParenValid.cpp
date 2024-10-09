#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {

        int open = 0, close = 0;

        for (char c : s) { //Greedy Algo to check balance
            if (c == '('){
                open++;
            } else {
             if (open > 0){
                open--;
            } else {
                close++;
            }
         }
        
        }
        return abs(open + close);
    }
};

class Tester :  public Solution {
public:
    Tester(string s) {
       
        cout << "The required addition of parentheses for the given string \"" << s << "\" is: " << minAddToMakeValid(s) <<endl;
    } 

};

auto main() -> int {

    string s1 = "(()";
    Tester test1(s1);

    string s2 = "(((";
    Tester test2(s2);

    string s3 = "()))((";
    Tester test3(s3);

    return 0;
}