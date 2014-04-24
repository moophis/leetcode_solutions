// http://oj.leetcode.com/problems/n-queens-ii/

class Solution {
    int N;
    vector<int> pos;   // pos[row] = col
    int sum;
    
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
    
    void update_col(int row, int col) {
        pos[row] = col;
    }
    
    void do_solve(int k) {
        if (k == N) {
            sum++;
            return;
        }
        
        for (int i = 0; i < N; i++) {  // for each column
            if (is_ok(k, i)) {
                update_col(k, i);      // (row, col)
                do_solve(k + 1);  // place (k+1)th queen
            }
        }
    }
public:
    int totalNQueens(int n) {
        N = n;
        sum = 0;
        pos.resize(N);
        do_solve(0); // try to solve the 0-th queen
        
        return sum;
    }
};