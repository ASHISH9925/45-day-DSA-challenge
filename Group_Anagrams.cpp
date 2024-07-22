//to make code faster 
#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();


//solution
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hello;
        for(string s : strs){
            string n = s;
            sort(s.begin(),s.end());
            hello[s].push_back(n);
        }

        vector<vector<string>> ans;

        for(auto i : hello){
            ans.push_back(i.second);
        }

        return ans;
    }
};