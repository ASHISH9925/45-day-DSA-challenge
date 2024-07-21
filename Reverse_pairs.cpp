//to make code faster 

typedef long long ll;

#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int hello = 0;
    void merge(vector<int>& array, int s, int e) {
        int i = s;
        int m = (s + e) / 2;
        int j = m + 1;
        vector<int> temp;

        int n = m+1;
        for(int h = s;h<=m;h++){
            while(n<=e && array[h] > 2*(long long)array[n]){
                n++;
            }
            hello += n -(m+1);
        }

        while (i <= m && j <= e) {
            if (array[i] < array[j]) {
                temp.push_back(array[i]);
                i++;
            } 
            else {
                temp.push_back(array[j]);
                j++;
            }
        }

        while (i <= m) {
            
            temp.push_back(array[i++]);
        }

        while (j <= e) {
            temp.push_back(array[j++]);
        }

        int k = 0;
        for (int i = s; i <= e; i++) {
            array[i] = temp[k++];
        }
    }

    void mergesort(vector<int>& array, int s, int e) {
        if (s >= e) {
            return;
        }

        int mid = (s + e) / 2;

        mergesort(array, s, mid);
        mergesort(array, mid + 1, e);
        merge(array, s, e);
    }


    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return hello;
    }
};