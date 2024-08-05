class Solution {
public:
    string minWindow(string big, string s) {
        map<char,int> hello;
        map<char,int> hi;
        int min_window_size = INT_MAX;

        int mini = -1,minj;
        //storing values of all variables
        for(int i = 0;i<s.size();i++){
            hello[s[i]] += 1;
        }


        int cnt = 0;
        int start = 0;

        //iterate over the pattern
        for(int i = 0;i<big.size();i++){
            //expanding the window by including current charecter
            char ch = big[i];
            hi[ch]++;

            if((hello[ch] != 0) && (hi[ch] <= hello[ch])){
                cnt++;
            }

            //if all charecters matched then we can start contracting

            if(cnt == s.size()){
                //start contracting from left to remove unwanted charecters

                while(hello[big[start]] == 0 or hi[big[start]] > hello[big[start]]){
                    hi[big[start]]--;
                    start++;
                }

                // note the window size
                
                int min_current = i-start+1;

                if(min_current < min_window_size){
                    min_window_size = min_current;
                    mini = i;
                    minj = start;
                }


            }


        }
        if(mini == -1){
            return "";
        }
        else{
            return big.substr(minj,min_window_size);
        }
    }
};