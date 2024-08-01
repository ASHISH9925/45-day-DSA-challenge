class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff(gas.size());
        int total_gas = 0;
        int total_cost = 0;

        for(int i = 0;i<gas.size();i++){
            total_gas += gas[i];
            total_cost += cost[i];
            diff[i] = gas[i] - cost[i];
        }

        if(total_gas - total_cost < 0){
            return -1;
        }

        for(int i = 0;i<diff.size();i++){
            int curr_sum = 0;
            int j = i;
            while(curr_sum >= 0 && j<diff.size()){
                curr_sum += diff[j];
                j++;
            }
            if(curr_sum >= 0){
                return i;
            }
            i = j-1;
        }

        return -1;
    }
};