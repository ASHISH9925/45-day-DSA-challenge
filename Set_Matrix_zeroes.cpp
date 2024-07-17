class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> hello;
        set<int> hello2;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    hello.insert(i);
                    hello2.insert(j);
                }
            }
        }

        for(int i : hello){
            for(int j = 0;j<matrix[i].size();j++){
                matrix[i][j] = 0;
            }
        }

        for(int i : hello2){
            for(int j = 0;j<matrix.size();j++){
                matrix[j][i] = 0;
            }
        }
        
    }
};