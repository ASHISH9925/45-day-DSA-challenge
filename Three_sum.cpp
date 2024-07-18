class Solution {
public:
    vector<vector<int>> twosum(vector<int>& hello, int target) {
        vector<vector<int>> final_result;
        for (int left = 0, right = hello.size() - 1; left < right;) {
            int mid_res = hello[left] + hello[right];

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

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i];
            vector<int> slicedVector(nums.begin() + i + 1, nums.end());

            vector<vector<int>> hello = twosum(slicedVector, target);

            for (int k = 0; k < hello.size(); ++k) {
                result.push_back({nums[i], hello[k][0], hello[k][1]});
            }
        }

        return result;
    }
};