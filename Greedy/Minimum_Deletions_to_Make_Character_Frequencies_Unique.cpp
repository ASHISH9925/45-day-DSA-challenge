#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minDeletions(string s) {
        map<char ,int> freq_map;
        map<int,bool> used;
        int subs = 0;

        int n = s.size();
        int max_num;
        for(int i = 0;i<n;i++){
            freq_map[s[i]]++;
            max_num = max(freq_map[s[i]],max_num);
        }

        for(int i = 0;i<= max_num;i++){
            used[max_num] = false;
        }

        for (auto it = freq_map.begin(); it != freq_map.end(); ++it) {
            char ch = it->first;
            int freq = it->second;

            while (freq > 0 && used[freq]) {
                freq--;
                subs++;
            }

            if (freq > 0) {
                used[freq] = true;
            }
        }

        return subs;
    }
};