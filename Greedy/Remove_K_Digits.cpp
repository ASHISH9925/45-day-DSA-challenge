class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num[0]=='0' || k>=num.size()) return "0";
        string hello = "";
        for(char c : num){
            while(hello.size() && c<hello.back() && k ){
                hello.pop_back();
                k--;
            }
            if(hello.size() || c-'0')
                hello.push_back(c);
        }
        while(k && hello.size()){
            hello.pop_back();
            k--;
        }
        if(!hello.size()) return "0";
       return hello;
    }
};