#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class MyStack {
public:

    queue<int> temp;
    queue<int> res;
    MyStack() {
        
    }
    
    void push(int x) {
        temp.push(x);
    }
    
    int pop() {
        while(temp.size() > 1){
            int y = temp.front();
            res.push(y);
            temp.pop();
        }

        int x = temp.front();
        temp.pop();

        while(res.size() != 0){
            int y = res.front();
            temp.push(y);
            res.pop();
        }

        return x;
    }
    
    int top() {
        while(temp.size() > 1){
            int y = temp.front();
            res.push(y);
            temp.pop();
        }

        int x = temp.front();
        res.push(x);
        temp.pop();

        while(res.size() != 0){
            int y = res.front();
            temp.push(y);
            res.pop();
        }

        return x;
    }
    
    bool empty() {
        if(temp.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */