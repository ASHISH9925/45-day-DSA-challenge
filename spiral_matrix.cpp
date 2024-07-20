class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> finale;
        if(matrix.empty() || matrix[0].empty()) {
            return finale;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int upper = 0, lower = m - 1, left_side_ = 0, right_side = n - 1;
        while(upper <= lower && left_side_ <= right_side) {
            for(int i = left_side_; i <= right_side; i++) {
                finale.push_back(matrix[upper][i]);
            }
            upper++;
            for(int i = upper; i <= lower; i++) {
                finale.push_back(matrix[i][right_side]);
            }
            right_side--;
            if(upper <= lower) {
                for(int i = right_side; i >= left_side_; i--) {
                    finale.push_back(matrix[lower][i]);
                }
                lower--;
            }
            if(left_side_ <= right_side) {
                for(int i = lower; i >= upper; i--) {
                    finale.push_back(matrix[i][left_side_]);
                }
                left_side_++;
            }
        }
        return finale;
    }
};