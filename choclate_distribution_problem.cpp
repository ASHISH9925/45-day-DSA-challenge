class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long i = 0;
        long long min_difference = INT_MAX;
        long long j = m -1;
        
        while(j < n){
            min_difference = min(min_difference,a[j]-a[i]);
            i++;j++;
        }
        
        //5 7 11 12 13 13 
        
        return min_difference;
    
    }   
};