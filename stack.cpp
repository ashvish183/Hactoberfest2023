#include <iostream>
#include <stack>

using namespace std;

void deleteMiddleElement(stack<int> &s, int middlePos) {
    stack<int> tempStack;

    while (middlePos > 1) {
        tempStack.push(s.top());
        s.pop();
        middlePos--;
    }

    s.pop();

    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> s;

    // Push some elements to the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int size = s.size();
    int middlePos = size / 2 + 1;

    deleteMiddleElement(s, middlePos);

    // Print the stack after deletion
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
