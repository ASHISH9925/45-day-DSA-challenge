#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i] >= goal-i){
                goal = i;
            }
        }

        if(goal == 0){return true;}
        return false;
    }
};