#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

bool sorte(vector<int> a,vector<int> b){
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),sorte);
        int sum1 = 0;
        stack<int> hello;
        hello.push(intervals[0][1]);

        for(auto i:intervals){
            if(hello.top() <= i[0]){
                hello.push(i[1]);
            }
            else{
                sum1++;
            }
        }

        return --sum1;
    }
};