#include <iostream>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n==1) return '0';

        int mid = (1 << (n - 1)); //Mid position 

        if (k == mid) {
            return '1';
        } else if (k < mid) {
            return findKthBit(n - 1, k);
        } else {
            char res = findKthBit(n - 1, mid - (k - mid));
            return res == '0' ? '1' : '0'; //Invert res
        }
    }
};

class Tester : public Solution {
public:
    Tester(int n, int k) {

        cout << findKthBit(n, k) << endl;
    }
};


auto main() -> int {

    int n1 = 3, k1 = 1;
    Tester test1(n1, k1);

    int n2 = 4, k2 = 11;
    Tester test2(n2, k2);

    return EXIT_SUCCESS;
}