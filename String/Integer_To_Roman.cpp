#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string intToRoman(int num) {
        map<int, char> roman = {
        {1, 'I'},
        {5, 'V'},
        {10, 'X'},
        {50, 'L'},
        {100, 'C'},
        {500, 'D'},
        {1000, 'M'}
    };

        string res;
        int i = 0;
        while(num>0){
            int n = num%10;
            num /= 10;

            if(n < 5 && n != 4){
                for(int k = 0;k<n;k++){
                    res += roman[1*pow(10,i)];
                }
            }
            else if(n == 5){
                res += roman[5*pow(10,i)];
            }
            else if(n > 5 && n != 9){
                for(int k = 0;k<n-5;k++){
                    res += roman[1*pow(10,i)];
                }
                res += roman[5*pow(10,i)];
            }
            else if(n == 4){
                res+= roman[5*pow(10,i)];
                res += roman[1*pow(10,i)];
            }
            else if(n == 9){
                res+= roman[10*pow(10,i)];
                res += roman[1*pow(10,i)];
            }

            i++;
        }

        reverse(res.begin(),res.end());
        return res;

    }
};