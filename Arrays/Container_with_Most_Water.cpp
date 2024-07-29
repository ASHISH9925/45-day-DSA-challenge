#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int var1=0,varr2=0,varrr3=0;
        int right_ptr=n-1,left_ptr=0;

        
        while(left_ptr<right_ptr){
            if(height[left_ptr]>height[right_ptr]){
                var1=min(height[right_ptr],height[left_ptr])*(abs(right_ptr-left_ptr));
                varrr3=max(var1,varrr3);
                right_ptr--;
            }
            else{
                varr2=min(height[right_ptr],height[left_ptr])*(abs(right_ptr-left_ptr));
                varrr3=max(varrr3,varr2);
                left_ptr++;
            }
        }
        return varrr3;
    }
};