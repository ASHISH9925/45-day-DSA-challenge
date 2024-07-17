class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int prev_ele_pos = 0;
        if(nums.size() == 1){return 1;}
        while(i<nums.size()){
            if(nums[i] != nums[prev_ele_pos]){
                swap(nums[i],nums[prev_ele_pos + 1]);
                prev_ele_pos+= 1;
            }

            i++;
        }

        return (prev_ele_pos+1);
    }
};