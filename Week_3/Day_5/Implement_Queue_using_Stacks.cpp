#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;

    // Move elements from input to output only when output is empty,
    // so we preserve overall FIFO order.
    void transfer() {
        if (output.empty()) 
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        
    }

public:
    MyQueue() {
        // Default constructor
    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        transfer();
        int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        transfer();
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }

};

int main() {
    MyQueue myQueue = MyQueue();
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek(); // return 1
    cout << myQueue.pop(); // return 1, queue is [2]
    cout << myQueue.empty(); // return false(0)

    return 0;
}