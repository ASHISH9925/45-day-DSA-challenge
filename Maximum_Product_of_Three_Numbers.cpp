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
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int max_prod = nums[n-1] * nums[n-2] * nums[n-3];
        max_prod = max(max_prod,(nums[0]*nums[1]*nums[2]));
        max_prod = max(max_prod,(nums[0]*nums[1]*nums[n-1]));

        return max_prod;
    }
};