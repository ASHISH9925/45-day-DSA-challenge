class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0,right = 1;
        int sum = 0;
        while(right<prices.size()){
            if(prices[left] > prices[right]){
                left = right;
                right += 1;
            }

            else{

                while(((right+1) < prices.size()) && (prices[right + 1] >= prices[right])){
                    right+=1;
                }

                sum += prices[right] - prices[left];
                left = right+1;
                right++;
            }

        }

        return sum;
    }
};