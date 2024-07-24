class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> hello(n);
        unordered_map<int,int> hi;
        hi[k] = 1;
        //if k is found to be one of the prefix sums then should return true 
        

        for(int i = 0;i<n;i++){
            if(i == 0){hello[0]= nums[0];}
            else{hello[i] = nums[i] + hello[i-1];}

            //s2 - s1 = k
            //storing k+s1 in arr until i find s2 using prefix sum

            

            if(hi[hello[i]] >= 1){
                //***********
                //debugger line ignore
                cout<<"YESS"<<" "<<hello[i]<<endl;
                //***********
                count += hi[hello[i]];
            }

            hi[k+hello[i]] += 1;
        }

        //***********
        //debugger line ignore
        for(auto i:hello){
            cout<<i<<" ";
        }
        //***********

        return count;
        
    }
};