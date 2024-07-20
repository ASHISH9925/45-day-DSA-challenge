//to make code faster 

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
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> pref(n);
        pref[0] = cardPoints[0];

        for(int i = 1;i<n;i++){
            pref[i] = cardPoints[i] + pref[i-1];
        }


        int max_sum = 0;

        for(int i = 0;i<k;i++){
            int front_sum = pref[k-i-1];
            int back_sum = pref[n-1] - pref[n-1-i];
            max_sum = max(max_sum,(back_sum+front_sum));
        }

        if(k < n){
            max_sum = max(max_sum,pref[n-1] - pref[n-k-1]);
        }



        return max_sum;

    }
};