//to make code faster 
#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        string prev = strs[0];
        for(string hi : strs){
            string sec_str;
            for(int i = 0;i<min(prev.size(),hi.size());i++){
                if(prev[i] == hi[i]){
                    sec_str += hi[i];
                }
                else{
                    break;
                }
            }

            prev = sec_str;
        }

        return prev;
    }
};