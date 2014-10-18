/**
 * The n-queens puzzle is the problem of placing n queens on 
 * an n¡Án chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions 
 * to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the 
 * n-queens' placement, where 'Q' and '.' both indicate a queen 
 * and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 *  [
 *   [".Q..",  // Solution 1
 *    "...Q",
 *    "Q...",
 *    "..Q."],
 *
 *   ["..Q.",  // Solution 2
 *    "Q...",
 *    "...Q",
 *    ".Q.."]
 *  ]
 */
 
class Solution {
    vector<string> generate(vector<int> &placement) {
        int N = placement.size();
        vector<string> ret;
        for (int i = 0; i < N; i++) {
            string s;
            for (int j = 0; j < N; j++) {
                s += (placement[i] == j) ? 'Q' : '.'; 
            }
            ret.push_back(s);
        }
        return ret;
    }
    
    bool valid(vector<int> &placement, int row, int col) {
        for (int i = 0; i < row; i++) {
            int j = placement[i];
            if (j == col || i - row == j - col || i - row == col - j) {
                return false;
            }
        }
        return true;
    }
    
    void solve(vector<vector<string> > &ret, vector<int> &placement, int cur_row, const int N) {
        if (cur_row == N) {
            ret.push_back(generate(placement));
            return;
        }
        
        for (int col = 0; col < N; col++) {
            if (valid(placement, cur_row, col)) {
                placement[cur_row] = col;
                solve(ret, placement, cur_row + 1, N);
            }
        }
    }
    
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        if (n <= 0) {
            return ret;
        }
        
        vector<int> placement(n);
        solve(ret, placement, 0, n);
        return ret;
    }
};