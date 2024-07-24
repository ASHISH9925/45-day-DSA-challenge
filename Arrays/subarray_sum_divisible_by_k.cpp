typedef long long ll;

#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();
        int prefix_sum = 0;
        int remainder = 0;
        vector<int> hi(k,0);
        hi[0] = 1;

        int res = 0;

        for(int i:nums){
            prefix_sum += i;
            remainder = prefix_sum % k;
            if(remainder<0) {remainder += k;}

            if(hi[remainder]){
                res += hi[remainder];
            }
            hi[remainder] += 1;

        }
        return res;
    }

};