#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> why;
        for(int x : nums){
            if(nums[abs(x)-1] < 0){
                why.push_back(abs(x));
            }
            nums[abs(x) - 1] *= -1;
        }

        return why;
    }
};