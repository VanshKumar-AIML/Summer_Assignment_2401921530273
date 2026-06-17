#include<iostream>
#include<stack>
using namespace std;

class MinStack {
private:
    stack<int> main_st;     // stack initialised
    stack<int> min_st;
public:
    MinStack() {
        // default constructor initialised
    }
    
    void push(int value) {
        main_st.push(value);      // push every value to main stack

        if(min_st.empty() || value <= min_st.top())
            min_st.push(value);           // push new min value

        else
            min_st.push(min_st.top());      // duplicate current minimum value
    }
    
    void pop() {
        main_st.pop();          // remove value from both stacks
        min_st.pop();
    }
    
    int top() {
        return main_st.top();           // give top value from the main stack
    }
    
    int getMin() {
        return min_st.top();        // min value exists in min stack
    }
};

int main() {
    // object created and methods used :
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // return -3
    minStack.pop();
    cout << minStack.top() << endl;    // return 0
    cout << minStack.getMin() << endl; // return -2

    return 0;
}