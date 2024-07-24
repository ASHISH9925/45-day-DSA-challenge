class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        vector<char> stack;
        unordered_map<char,int> braks;
        braks['('] = ')';
        braks['['] = ']';
        braks['{'] = '}';


        for(int i = 0;i<n;i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stack.push_back(s[i]);
            }
            else if(stack.size() >= 1 && s[i] == braks[stack.back()]){
                stack.pop_back();
                
            }
            else{
                return false;
            }
        }

        if(stack.size() != 0){
            return false;
        }

        return true;
    }
};