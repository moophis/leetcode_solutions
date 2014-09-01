// https://oj.leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string S, string T) {
        int ssize = S.size(), tsize = T.size();
        if (ssize < tsize || ssize == 0) {
            return "";
        }

        int wbegin = 0;
        int win_len = INT_MAX;
        int win_begin = -1;
        int expect[256], actual[256];
        int nr_covered = 0;
        memset(expect, 0, 256 * sizeof(int));
        memset(actual, 0, 256 * sizeof(int));
        
        for (int i = 0; i < tsize; i++) {
            expect[T[i]]++;
        }
        
        for (int wend = 0; wend < ssize; wend++) {
            if (expect[S[wend]] > 0) {
                actual[S[wend]]++;
                if (actual[S[wend]] <= expect[S[wend]]) {
                    nr_covered++;
                }
            }
            if (nr_covered == tsize) {
                // move behind pointer forward
                while (expect[S[wbegin]] == 0
                       || expect[S[wbegin]] < actual[S[wbegin]]) {
                    actual[S[wbegin]]--;
                    wbegin++;
                }
                if (win_len > wend - wbegin + 1) {
                    win_len = wend - wbegin + 1;
                    win_begin = wbegin;
                }
            }
        }
        
        return (win_len == INT_MAX) ? "" : S.substr(win_begin, win_len);
    }
};
