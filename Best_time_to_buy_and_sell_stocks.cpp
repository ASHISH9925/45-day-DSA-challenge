class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int left = 0;
        int current_max= 0;

        for(int right = 1;right<prices.size();right++){
            if(prices[left] > prices[right]){
                left = right;
            }
            else{
                current_max = max(current_max,prices[right] - prices[left]);
            }
        }

        return current_max;

    }
};