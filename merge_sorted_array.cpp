class Solution {
public:
    void merge(vector<int>& nums, int m, vector<int>& nums2, int n) {
        int i = m+n-1;
        int p1 = m - 1;
        int p2 = n - 1;

        while(p1 >= 0 && p2 >= 0){
            if(nums[p1] >nums2[p2]){
                nums[i] = nums[p1];
                p1--;
            }
            else{
                nums[i] = nums2[p2];
                p2--;
            }
            i--;
        }

        while(p2 >= 0){
            nums[i] = nums2[p2];
            i--;p2--;
        }
    }
};
