class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> compliments;
        vector<int> result;
        for(int i =0;i< nums.size();i++){
            if(compliments.find(nums[i]) != compliments.end()){
                result.push_back(compliments[nums[i]]);
                result.push_back(i);
                return result;   
            }
            compliments[target - nums[i]] = i;
        }
    return result;
    }
};