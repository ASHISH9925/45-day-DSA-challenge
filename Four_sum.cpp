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
    vector<vector<ll>> twosum(vector<ll>& hello, long long target) {
        vector<vector<ll>> final_result;
        int left = 0, right = hello.size() - 1;
        while (left < right) {
            ll mid_res = hello[left] + hello[right];
            if (mid_res == target) {
                final_result.push_back({hello[left], hello[right]});
                ++left;
                --right;

                // Skip duplicate elements
                while (left < right && hello[left] == hello[left - 1])
                    ++left;
                while (left < right && hello[right] == hello[right + 1])
                    --right;
            } else if (mid_res < target) {
                ++left;
            } else {
                --right;
            }
        }
        return final_result;
    }

    vector<vector<ll>> threeSum(vector<ll>& nums, long long target) {
        vector<vector<ll>> result;
        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            ll target2 = (long long )target - (long long)nums[i];
            vector<ll> slicedVector(nums.begin() + i + 1, nums.end());
            vector<vector<ll>> hello = twosum(slicedVector, target2);

            for (int k = 0; k < hello.size(); ++k) {
                result.push_back({nums[i], hello[k][0], hello[k][1]});
            }
        }
        return result;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            ll target2 = (long long)target - (long long)nums[i];
            vector<ll> slicedVector(nums.begin() + i + 1, nums.end());
            vector<vector<ll>> hello = threeSum(slicedVector, target2);

            for (vector<ll> hi : hello) {
                res.push_back({nums[i],(int)hi[0], (int)hi[1], (int)hi[2]});
            }
        }
        return res;
    }
};