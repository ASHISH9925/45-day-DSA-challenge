#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> hello;
        for(int i = 0;i<nums.size();i++){
            hello[nums[i]] += 1;
            if(hello[nums[i]] == 2){
                return nums[i];
            } 
        }

        return 1;
    }
};