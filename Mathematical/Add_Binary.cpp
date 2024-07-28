class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int carry = 0;
        string ans;
        int i = 0;

        while(i<a.size() && i<b.size()){
            int num = 0;
            if(a[i] != '0')num+= 1;
            if(b[i] != '0')num+= 1;

            if(num+carry == 3){
                ans.push_back('1');
                carry = 1;
            }
            else if(num + carry == 2){
                ans.push_back('0');
                carry = 1;
            }
            else if(num + carry == 1){
                ans.push_back('1');
                carry = 0;
            }
            else if(num + carry == 0){
                ans.push_back('0');
                carry = 0;
            }

            i++;
        }

        while(i<a.size()){
            int num = 0;
            if(a[i] != '0')num+= 1;

            if(num + carry == 2){
                ans.push_back('0');
                carry = 1;
            }
            else if(num + carry == 1){
                ans.push_back('1');
                carry = 0;
            }
            else if(num + carry == 0){
                ans.push_back('0');
                carry = 0;
            }

            i++;
            
        }
        while(i<b.size()){

            int num = 0;
            if(b[i] != '0')num+= 1;

            if(num + carry == 2){
                ans.push_back('0');
                carry = 1;
            }
            else if(num + carry == 1){
                ans.push_back('1');
                carry = 0;
            }
            else if(num + carry == 0){
                ans.push_back('0');
                carry = 0;
            }
            i++;
        }

        if(carry == 1){
            ans.push_back('1');
        }


        reverse(ans.begin(),ans.end());
        return ans;
    }
};