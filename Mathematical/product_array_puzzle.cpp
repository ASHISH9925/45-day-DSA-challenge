//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       long long int zs = 0,total_prod = 1;
        vector<long long int> newnums;

        for(long long int i = 0 ;i<nums.size();i++){
           if(nums[i] == 0){zs += 1;continue;}
           else{total_prod *= nums[i];}
        }
        if(zs>=2){
            for(long long int i = 0 ;i<nums.size();i++){
                newnums.push_back(0);
            }
        }
        else if(zs == 1){
            for(long long int i = 0 ;i<nums.size();i++){
                if(nums[i] == 0){newnums.push_back(total_prod);}
                else{newnums.push_back(0);}
        }
        }
        else{
            for(long long int i = 0 ;i<nums.size();i++){
                newnums.push_back(total_prod/nums[i]);
        }
        }

        return newnums;
        //code here        
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends