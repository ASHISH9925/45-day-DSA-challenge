#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string hello;
        string hello2;
        for(char i:s){
            if(i == '#' && hello.size()!= 0){
                hello.pop_back();
            }
            else if(i != '#'){
                hello.push_back(i);
            }
        }
        for(char i:t){
            if(i == '#' && hello2.size()!= 0){
                hello2.pop_back();
            }
            else if(i != '#'){
                hello2.push_back(i);
            }
        }


        if(hello == hello2){
            return true;
        }
        else{
            return false;
        }
    }
};