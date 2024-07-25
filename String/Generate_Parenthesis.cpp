#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:

    void parans(int closed,int open,vector<string>& hello,string& paras){
        //base case if open == 0 and closed == 0

        if(open == 0 && closed == 0){
            hello.push_back(paras);
            return;
        }

        if(open == closed){
            string op1 = paras;
            op1.push_back('(');
            parans(closed,open-1,hello,op1);
        }

        else if(open == 0){
            string op1 = paras;
            op1.push_back(')');
            parans(closed-1,open,hello,op1);
            
        }

        else if(closed == 0){
            string op1 = paras;
            op1.push_back('(');
            parans(closed,open-1,hello,op1);
        }

        else{
            string op1 = paras;
            op1.push_back(')');
            parans(closed-1,open,hello,op1);
            op1 = paras;
            op1.push_back('(');
            parans(closed,open-1,hello,op1);
        }

        return;
    }


    vector<string> generateParenthesis(int n) {
        vector<string> hello;
        string hi = "";
        parans(n,n,hello,hi);

        return hello;
    }
};