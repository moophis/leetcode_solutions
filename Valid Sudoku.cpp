// http://oj.leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() != 9) {
            return false;
        }
        
        unsigned short row[9], col[9], block[9];
        memset(row, 0, 9*sizeof(unsigned short));
        memset(col, 0, 9*sizeof(unsigned short));
        memset(block, 0, 9*sizeof(unsigned short));
        
        for (int i = 0; i < 9; i++) {
            if (board[i].size() != 9) {
                return false;
            }
            
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                
                if (c == '.') {
                    continue;
                }
                if (!isdigit(c)) {
                    return false;
                }
                
                int d = (unsigned short) (c - '0');
                
                // check row
                if (row[i] & (1 << d)) {
                    return false;
                } else {
                    row[i] |= (1 << d);
                }
                
                // check column
                if (col[j] & (1 << d)) {
                    return false;
                } else {
                    col[j] |= (1 << d);
                }
                
                // check block
                int blk = 3 * (i / 3) + (j / 3);
                if (block[blk] & (1 << d)) {
                    return false;
                } else {
                    block[blk] |= (1 << d);
                }
            }
        }
        
        return true;
    }
};