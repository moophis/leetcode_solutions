// http://oj.leetcode.com/problems/surrounded-regions/

class Solution {
    void infect_dfs(vector<vector<char>> &board, int row, int col) {
        if (row < 0 || col < 0 || row >= board.size() 
            || col >= board[row].size()) {
            return;    
        }
        
        if (board[row][col] == 'X' || board[row][col] == 'I') {
            return;
        }
        
        // else: board[row][col] == 'O'
        board[row][col] = 'I';
        infect(board, row - 1, col);
        infect(board, row + 1, col);
        infect(board, row, col - 1);
        infect(board, row, col + 1);
    }
    
    void infect_bfs(vector<vector<char>> &board, int row, int col) {
        queue<pair<int, int> > q;   // <row, col>
        
        q.push(make_pair(row, col));
        while (!q.empty()) {
            pair<int, int> t = q.front();
            int row = t.first;
            int col = t.second;
            
            q.pop();
            
            if (row < 0 || col < 0 || row >= board.size() 
                || col >= board[row].size()) {
                continue;        
            }
            
            if (board[row][col] == 'X' || board[row][col] == 'I') {
                continue;
            }
            
            // else: board[row][col] == 'O'
            board[row][col] = 'I';
            q.push(make_pair(row - 1, col));
            q.push(make_pair(row + 1, col));
            q.push(make_pair(row, col - 1));
            q.push(make_pair(row, col + 1));
        }
    }
    
    void infect(vector<vector<char>> &board, int row, int col) {
        infect_bfs(board, row, col);
    }
    
    public:
    void solve(vector<vector<char>> &board) {
        if (board.size() < 3 || board[0].size() < 3) {
            return;
        }
        
        const int M = board.size();
        const int N = board[0].size();
        
        // begin from the 4 edges
        for (int i = 0; i < M; i++) {
            infect(board, i, 0);
            infect(board, i, board[0].size() - 1);
        }
        for (int i = 0; i < N; i++) {
            infect(board, 0, i);
            infect(board, board.size() - 1, i);
        }
        
        // all 'I' should be converted back to 'O'
        // all 'O' should be converted to 'X'
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                switch (board[i][j]) {
                case 'I':
                    board[i][j] = 'O';
                    break;
                case 'O':
                    board[i][j] = 'X';
                    break;
                case 'X':
                default:
                    break;
                }
            }
        }
    }
};