#include <iostream>
#include <vector>

class CustomStack {
private:
    std::vector<int> stack;  // Vector to hold stack elements
    int maxSize;             // Maximum size of the stack

public:
    // Constructor to initialize stack with a given max size
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    // Push element x onto the stack if it has not reached max size
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    // Pop and return the top element from the stack, or return -1 if the stack is empty
    int pop() {
        if (stack.empty()) {
            return -1;
        }
        int topElement = stack.back();
        stack.pop_back();
        return topElement;
    }

    // Increment the bottom k elements of the stack by val
    void inc(int k, int val) {
        // We should only increment up to the smaller of k and the stack's current size
        int limit = std::min(k, (int)stack.size());
        for (int i = 0; i < limit; ++i) {
            stack[i] += val;
        }
    }
};

// Driver function to test the CustomStack class
int main() {
    CustomStack stk(3);      // Stack with max size of 3

    stk.push(1);             // stack becomes [1]
    stk.push(2);             // stack becomes [1, 2]
    std::cout << stk.pop() << std::endl;  // Return 2, stack becomes [1]

    stk.push(2);             // stack becomes [1, 2]
    stk.push(3);             // stack becomes [1, 2, 3]
    stk.push(4);             // stack stays [1, 2, 3], cannot add more elements (max size reached)

    stk.inc(5, 100);         // Increment bottom 5 elements by 100 -> stack becomes [101, 102, 103]
    stk.inc(2, 100);         // Increment bottom 2 elements by 100 -> stack becomes [201, 202, 103]

    std::cout << stk.pop() << std::endl;  // Return 103, stack becomes [201, 202]
    std::cout << stk.pop() << std::endl;  // Return 202, stack becomes [201]
    std::cout << stk.pop() << std::endl;  // Return 201, stack becomes []
    std::cout << stk.pop() << std::endl;  // Return -1, stack is empty
}
