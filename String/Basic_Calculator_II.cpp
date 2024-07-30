#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> hello;
        string curr = "";
        char curr_op = '+';


        for(int i = 0;i<n;i++){

            if(isdigit(s[i])){
                curr += s[i];
                cout<<curr<<" ";
            }
            else if(s[i] == ' '){
                continue;
            }
            else{      
                if(curr_op == '+' ){
                    hello.push(stoi(curr));
                    curr = "";
                }
                else if(curr_op == '-'){
                    hello.push(- stoi(curr));
                    curr = "";
                }
                else if(curr_op == '*'){
                    int hi = hello.top();
                    hello.pop();
                    hi = hi * stoi(curr);

                    hello.push(hi);
                    curr = "";
                }
                else if(curr_op == '/'){
                    int hi = hello.top();
                    hello.pop();
                    hi = hi / stoi(curr);

                    hello.push(hi);
                    curr = "";
                }

                curr_op = s[i];

            }
        }

        if (!curr.empty()) {
            if (curr_op == '+') {
                hello.push(stoi(curr));
            } else if (curr_op == '-') {
                hello.push(-stoi(curr));
            } else if (curr_op == '*') {
                int hi = hello.top();
                hello.pop();
                hi = hi * stoi(curr);
                hello.push(hi);
            } else if (curr_op == '/') {
                int hi = hello.top();
                hello.pop();
                hi = hi / stoi(curr);
                hello.push(hi);
            }
        }

        int sum = 0;
        while(hello.size()>0){
            sum += hello.top();
            hello.pop();
        }


        return sum;
    }
};