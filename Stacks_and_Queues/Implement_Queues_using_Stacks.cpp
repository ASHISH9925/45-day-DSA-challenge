#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class MyQueue {
public:
    stack<int> temp;
    stack<int> res;
    MyQueue() {
    }
    
    void push(int x) {
        temp.push(x);
    }
    
    int pop() {
        while(temp.size() != 0){
            int y = temp.top();
            res.push(y);
            temp.pop();
        }
        int x = res.top();
        res.pop();
        while(res.size() != 0){
            int y = res.top();
            temp.push(y);
            res.pop();
        }
        return x;
    }
    
    int peek() {
        while(temp.size() != 0){
            int y = temp.top();
            res.push(y);
            temp.pop();
        }
        int x = res.top();
        while(res.size() != 0){
            int y = res.top();
            temp.push(y);
            res.pop();
        }
        return x;
    }
    
    bool empty() {
        if(temp.size() == 0){
            return true;
        }
        else{return false;}
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */