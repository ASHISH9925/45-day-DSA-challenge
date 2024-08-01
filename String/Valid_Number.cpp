class Solution {
public:
    bool isNumber(string s) {
        //if only made of numbers then valid 
        //if only dot and then digits then valid
        //if e followed by number then end of loop without any special charecters then valid
        //if any letter except e return false
        //if one sign in front then valid
        //if sign in between of number then wrong so sign always at first pos

        if(s.size() == 1){
            if(!isdigit(s[0])){
                return false;
            }
        }


        int n = s.size();
        bool e_appeared = false;
        bool decimal_appeared = false;
        bool digits_after_e = false;
        bool digits_before_e = false;
        bool digits_in_general = false;

        for(int i = 0;i<n;i++){
            cout<<s[i]<<" ";
            if(isdigit(s[i])){
                if(e_appeared){
                    digits_after_e = true;
                }
                if(!e_appeared){
                    digits_before_e = true;
                }
                digits_in_general = true;
                continue;
            }
            else if(isalpha(s[i])){
                if(e_appeared == true){
                    cout<<"case 1";
                    return false;
                }
                if(s[i] != 'E' && s[i] != 'e'){
                    cout<<"case 2";
                    return false;
                } 
                if(i == 0){
                    cout<<"case 3";
                    return false;
                }
                e_appeared = true;
            }

            else if(s[i] == '-' || s[i] == '+'){
                if(i != 0 && (s[i-1] != 'E' && s[i-1] != 'e')){
                    return false;
                }
            }

            else if(s[i] == '.'){
                if(decimal_appeared == true){
                    return false;
                }
                if(i == 0 && n == 1){
                    return false;
                }
                if(e_appeared == true){
                    return false;
                }
                decimal_appeared = true;
            }

        }


        if(e_appeared && (!digits_after_e || !digits_before_e)){
            return false;
        }
        if(decimal_appeared && !digits_in_general){
            return false;
        }
        return true;
    }
};