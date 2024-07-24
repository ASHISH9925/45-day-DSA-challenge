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
    int strStr(string haystack, string needle) {
        int n = haystack.size(),m = needle.size();
        for(int i = 0;i<n;i++){
            if(needle == haystack.substr(i, m)){
                return i;
            }
        }

        return -1;
    }
};