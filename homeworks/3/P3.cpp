#include<iostream>
#include<stack>

using namespace  std;

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int priority(char symbol) {
    int priority = 0;
    if (symbol ==  '+') {
        priority = 1;
    } else if (symbol == '*') {
        priority = 2;
    }
    return priority;
}
string toReversePolish(string line) {
    stack<char> stack;
    string answer;
    for (char symbol : line) {
        if (isDigit(symbol)) {
            answer.push_back(symbol);
            answer.push_back(' ');
        } else if (symbol == '(') {
            stack.push(symbol);
        } else if (symbol == ')') {
            char temp = stack.top();
            stack.pop();
            while (temp != '(') {
                answer.push_back(temp);
                answer.push_back(' ');
                temp = stack.top();
                stack.pop();
            }
        } else {
            while (!stack.empty() && priority(stack.top()) >= priority(symbol)) {
                answer.push_back(stack.top());
                answer.push_back(' ');
                stack.pop();
            }
            stack.push(symbol);
        }
    }
    while (!stack.empty()) {
        answer.push_back(stack.top());
        answer.push_back(' ');
        stack.pop();
    }
    return answer;
}

int main() {
    string input;
    cin >> input;
    cout << toReversePolish(input);
    return 0;
}