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
    vector<string> strbuf;
    int N;
    vector<int> pos;   // pos[row] = col
    
    bool is_ok(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (pos[i] == col                // same colunm
               || row - i == col - pos[i]   // same diagonal 
               || row - i == pos[i] - col) { // same diagonal
                return false;
            }
        }
        
        return true;
    }
    
    string place_q_at(int col) {
        string s = "";
        
        for (int i = 0; i < N; i++) {
            s += (col == i) ? "Q" : ".";
        }
        
        return s;
    }
    
    void update_col(int row, int col) {
        pos[row] = col;
    }
    
    void do_solve(vector<vector<string> > &ret, int k) {
        if (k == N) {
            vector<string> strbuf;
            
            for (int i = 0; i < N; i++) {
                strbuf.push_back(place_q_at(pos[i]));
            }
            ret.push_back(strbuf);
            return;
        }
        
        for (int i = 0; i < N; i++) {  // for each column
            if (is_ok(k, i)) {
                update_col(k, i);      // (row, col)
                do_solve(ret, k + 1);  // place (k+1)th queen
            }
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        
        N = n;
        pos.resize(N);
        do_solve(ret, 0); // try to solve the 0-th queen
        
        return ret;
    }
};