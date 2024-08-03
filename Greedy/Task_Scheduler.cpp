#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        vector<int> hello(26,0);
        int n = tasks.size();

        for(int i = 0;i<n;i++){
            hello[tasks[i] - 'A'] += 1;
        }
        sort(hello.begin(),hello.end());

        int max_freq = hello[25];
        int vacant_blocks = max_freq-1;
        int ideal_spots = vacant_blocks * k;

        for(int i = 24;i>=0;i--){
            ideal_spots -= min(vacant_blocks,hello[i]);
        }

        if(ideal_spots <= 0){
                return n;
        }
        return n + ideal_spots;
    }
};
