#include <queue>

class StackUsingQueue {
private:
    std::queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        std::swap(q1, q2); // Swap the queues to keep q2 as the main storage
    }

    int pop() {
        int top = q2.front();
        q2.pop();
        return top;
    }

    int top() {
        return q2.front();
    }

    bool empty() {
        return q2.empty();
    }
};
