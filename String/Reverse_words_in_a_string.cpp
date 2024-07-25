class Solution {
public:
    vector<string> tokenizer(const string& input) {
        vector<string> tokens;
        
        char* strCopy = new char[input.size() + 1];
        strcpy(strCopy, input.c_str());

        // Tokenize the string based on spaces using strtok
        char* token = strtok(strCopy, " ");
        while (token != nullptr) {
            tokens.push_back(token);
            token = strtok(nullptr, " ");
        }

        return tokens;
    }
    string reverseWords(string s) {
        
        string hi;
        vector<string> hello = tokenizer(s);

        for(int i = hello.size()-1;i>0;i--){
            hi += hello[i] + " ";
        }
        hi += hello[0];
        
        return hi;
    }
};
