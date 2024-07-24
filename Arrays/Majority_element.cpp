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
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int,int> hello;
        for(int i = 0;i<nums.size();i++){
            hello[nums[i]] += 1;
        }

        for(auto i : hello){
            if(i.second >= n/2+1){
                return i.first;
            }
        }
        
        return -1;

    }
};