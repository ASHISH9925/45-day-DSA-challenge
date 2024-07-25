#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr;

        if(path == "/../"){
            return "/";
        }

        for(int i = 0;i<path.size();i++){
            if(path[i] == '/'){
                if(stack.size() >= 1 && curr == ".."){
                    stack.pop_back();
                }
                else if(curr != "" && curr != "." && curr !=".."){
                    stack.push_back(curr);
                }
                curr = "";
            }

            else{
                curr += path[i];
            }
        }

        if(curr != ""){
            if(stack.size() >= 1 && curr == ".."){
                stack.pop_back();
            }
            else if(curr != "." && curr != ".."){
                stack.push_back(curr);
            }
        }

        string res = "/";

        for(auto i:stack){
            res += i;
            res += "/";
        }

        if(res.size()>1)res.pop_back();

        return res;
    }
};