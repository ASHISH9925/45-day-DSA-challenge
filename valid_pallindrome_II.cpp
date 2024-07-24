//to make code faster 
#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int temp = 1;int temp1 = 1,temp2 = 1;
        int i,j;
        if(n == 3){
            if(s[0] != s[1] && s[1] != s[2] && s[0] != s[2]){
                return false;
            }
            return true;
        }

        for(i = 0,j=n-1;i<n/2 && j>n/2;i++,j--){
            if(s[i] != s[j] && temp == 1){
                temp = 0;
                break;
            }
        }

        if(temp == 0){
            for(int l = i+1,m=j;l<n/2 && m>((n/2) - 1);l++,m--){
                if(s[l] != s[m]){
                    temp1 = 0;
                    break;
                }
            }
            
            for(int l = i,m=j-1;l<n/2 && m>((n/2) - 1);l++,m--){
                if(s[l] != s[m]){
                    temp2 = 0;
                    break;
                }
            }
        }

        if(temp1 == 0 && temp2 == 0){
            return false;
        }

        return true;
    }
};