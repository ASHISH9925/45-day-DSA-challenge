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
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid = nums[n/2];
        long long sum = 0;
        
        for(int i = 0;i<n;i++){
            sum += abs(mid-nums[i]);
        }

        return sum;

        
    }
};