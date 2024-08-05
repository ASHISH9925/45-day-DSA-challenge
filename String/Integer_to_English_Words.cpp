#pragma GCC optimize("O1", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string numberToWords(int num) {
    if(num == 0){
        return "Zero";
    }
    map<int, string> vals ={{1000000000, "Billion"}, {1000000, "Million"}, 
    {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"},
    {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, 
    {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, 
    {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, 
    {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

    string final_string;

    while(num != 0){
        if(num >= 1000000000){
            final_string += vals[(num/1000000000)] + ' ';
            final_string += vals[1000000000] + ' ';
            num = num%1000000000;
        }

        else if(num >= 1000000){
            //convert into 100s
            int temp_num = num/1000000;

            //if 3 digit
            if(temp_num >= 100){
                //add first digit in number
                final_string += vals[temp_num/100] + ' ';
                temp_num = temp_num%100;
                final_string += vals[100] + ' ';

                //add second and third digit
                if(temp_num <=20 && temp_num >0){
                    final_string += vals[temp_num] + ' ';
                }
                else{
                    if((temp_num/10) * 10 != 0)
                    {final_string += vals[(temp_num/10) * 10] + ' ';}
                    if((temp_num%10) != 0)
                    {final_string += vals[temp_num%10] + ' ';}
                }

                final_string += vals[1000000] + ' ';
            }

            //if 2 digit
            else{
                if(temp_num!= 0 && temp_num< 100){
                    if(temp_num <=20 && temp_num >0){
                    final_string += vals[temp_num] + ' ';
                    }
                    else{
                        if((temp_num/10) * 10 != 0)
                        {final_string += vals[(temp_num/10) * 10] + ' ';}
                        if((temp_num%10) != 0)
                        {final_string += vals[temp_num%10] + ' ';}
                    }
                }

                final_string += vals[1000000] + ' ';
            }

            num = num%1000000;

        }


        else if(num >= 1000){
            //convert into 100s
            int temp_num = num/1000;

            //if 3 digit
            if(temp_num >= 100){
                //add first digit in number
                final_string += vals[temp_num/100] + ' ';
                temp_num = temp_num%100;
                final_string += vals[100] + ' ';

                //add second and third digit
                if(temp_num <=20 && temp_num >0){
                    final_string += vals[temp_num] + ' ';
                }
                else{
                    if((temp_num/10) * 10 != 0)
                    {final_string += vals[(temp_num/10) * 10] + ' ';}
                    if((temp_num%10) != 0)
                    {final_string += vals[temp_num%10] + ' ';}
                }

                final_string += vals[1000] + ' ';
            }

            //if 2 digit 
            else{
                if(temp_num!= 0 && temp_num< 100){
                    if(temp_num <=20 && temp_num >0){
                        final_string += vals[temp_num] + ' ';
                    }
                    else{
                        if((temp_num/10) * 10 != 0)
                        {final_string += vals[(temp_num/10) * 10] + ' ';}
                        if((temp_num%10) != 0)
                        {final_string += vals[temp_num%10] + ' ';}
                    }
                }

                final_string += vals[1000] + ' ';
            }

            

            num = num%1000;
        }

        else{
            int temp_num = num;
            if(temp_num >= 100){
                //add first digit in number
                final_string += vals[temp_num/100] + ' ';
                final_string += vals[100] + ' ';
                temp_num = temp_num%100;

                //add second and third digit
                if(temp_num <=20 && temp_num >0){
                    final_string += vals[temp_num] + ' ';
                }
                else{
                    if((temp_num/10) * 10 != 0)
                    {final_string += vals[(temp_num/10) * 10] + ' ';}
                    if((temp_num%10) != 0)
                    {final_string += vals[temp_num%10] + ' ';}
                }
            }   
            else{
                if(temp_num!= 0 && temp_num< 100){
                    if(temp_num <=20 && temp_num >0){
                    final_string += vals[temp_num] + ' ';
                    }
                    else{
                        if((temp_num/10) * 10 != 0)
                        {final_string += vals[(temp_num/10) * 10] + ' ';}
                        if((temp_num%10) != 0)
                        {final_string += vals[temp_num%10] + ' ';}
                    }
                }
            }
            break;
        }
    }

    size_t endPos = final_string.find_last_not_of(' ');
    final_string = final_string.substr(0, endPos + 1);
    
    return final_string;

    }
};