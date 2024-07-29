#include <iostream>
#include <deque>
using namespace std;


template<typename T>
class MyQueue {
private:
    std::deque<T> dq;

public:
    void push(const T& element) {
        dq.push_back(element);
    }

    T pop() {
        if (dq.empty()) {
            throw out_of_range("Queue is empty");
        }
        T frontValue = dq.front();
        dq.pop_front();
        return frontValue;
    }

    T front() const {
        if (dq.empty()) {
            throw out_of_range("Queue is empty");
        }
        return dq.front();
    }

    T back() const {
        if (dq.empty()) {
            throw out_of_range("Queue is empty");
        }
        return dq.back();
    }

    bool empty() const {
        return dq.empty();
    }

    size_t size() const {
        return dq.size();
    }
};


template<typename T>
class MyStack {
private:
    deque<T> dq;

public:
    void push(const T& element) {
        dq.push_back(element);
    }

    void pop() {
        if (dq.empty()) {
            throw out_of_range("Stack is empty");
        }
        dq.pop_back();
    }

    T top() const {
        if (dq.empty()) {
            throw out_of_range("Stack is empty");
        }
        return dq.back();
    }

    bool empty() const {
        return dq.empty();
    }

    size_t size() const {
        return dq.size();
    }
};
