#include <iostream>
#include <stack>

class QueueWithStacks {
    std::stack<int> inStack, outStack;

    void transfer() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    void enqueue(int val) {
        inStack.push(val);
    }

    int dequeue() {
        transfer();
        if (outStack.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    bool isEmpty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    QueueWithStacks q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << q.dequeue() << std::endl; // 1
    std::cout << q.dequeue() << std::endl; // 2

    q.enqueue(4);
    std::cout << q.dequeue() << std::endl; // 3

    return 0;
}