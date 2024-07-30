#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string convertToTitle(int cn) {
        string res;
        while(cn>0){
            cn--;
            //simple way to calculate the increment from a noted
            res = char(cn%26 + 'A') +res;
            cn = cn/26;
        }

        return res;
    }
};