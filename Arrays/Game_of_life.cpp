#pragma GCC optimize("O3", "unroll-loops")

const static auto fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int check_cell(int i, int j, vector<vector<int>>& arr) {

        int live = 0;

        // right cell
        if (j < arr[i].size() - 1 && arr[i][j + 1] == 1) {
            live += 1;
        }

        // right lower diagonal
        if (j < arr[i].size() - 1 && i < arr.size() - 1 &&
            arr[i + 1][j + 1] == 1) {
            live += 1;
        }

        // down cell
        if (i < arr.size() - 1 && arr[i + 1][j] == 1) {
            live += 1;
        }

        // left lower diagonal cell
        if (j > 0 && i > 0 && arr[i - 1][j - 1] == 1) {
            live += 1;
        }

        // left cell
        if (j > 0 && arr[i][j - 1] == 1) {
            live += 1;
        }

        // left upper diagonal cell
        if (i < arr.size()-1 && j > 0 && arr[i + 1][j - 1] == 1) {
            live += 1;
        }

        // upper cell
        if (i > 0 && arr[i - 1][j] == 1) {
            live += 1;
        }

        // upper right diagonal
        if (i > 0 && j < arr[i].size() - 1 && arr[i - 1][j + 1] == 1) {
            live += 1;
        }

        return live;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int col = board[0].size();

        // vector<vector<int>> soln;
        vector<vector<int>> soln(rows, vector<int>(col));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                soln[i][j] = check_cell(i, j, board);
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                if (soln[i][j] < 2 || soln[i][j] > 3) {
                    board[i][j] = 0;
                } else if (soln[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};