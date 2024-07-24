#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int x = nums.size();
        nums.erase(remove(nums.begin(),nums.end() , 0),nums.end());
        while(x != nums.size()){
            nums.push_back(0);
        }
    }
};