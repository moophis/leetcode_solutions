// https://oj.leetcode.com/problems/word-search/

class Solution {
    int M;
    int N;

    bool dfs(vector<vector<char> > &board, string &word, int str_idx, 
                int row, int col, vector<vector<bool> > &visited) {
        if (str_idx == word.size()) {
            return true;
        }            
        if (row < 0 || row >= M || col < 0 || col >= N) {
            return false;
        }
        if (word[str_idx] != board[row][col]) {
            return false;
        }
        if (visited[row][col]) {
            return false;
        }
           
        visited[row][col] = true;
        bool ret = (dfs(board, word, str_idx + 1, row + 1, col, visited) ||
                    dfs(board, word, str_idx + 1, row - 1, col, visited) ||
                    dfs(board, word, str_idx + 1, row, col + 1, visited) ||
                    dfs(board, word, str_idx + 1, row, col - 1, visited));
        visited[row][col] = false;
        return ret;
    }

public:
    bool exist(vector<vector<char> > &board, string word) {
        M = board.size();
        if (M == 0) {
            return false;
        }
        N = board[0].size();
        if (N == 0 || word.empty()) {
            return true;
        } 
        
        vector<vector<bool> > visited(M, vector<bool>(N, false));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};