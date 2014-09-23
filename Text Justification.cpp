// https://oj.leetcode.com/problems/text-justification/

class Solution {
    string gen_space(int num) {
        string spaces;
        for (int i = 0; i < num; i++) {
            spaces += ' ';
        }
        return spaces;
    }
    
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        
        int size = words.size();
        if (size == 0) {
            return ret;
        }
        
        int i = 0;
        while (i < size) {
            int words_len = 0;
            int nr_words = 0;
            int j;
            for (j = i; j < size; j++) {
                int wsize = words[j].size();
                if (words_len + wsize + j - i > L) {
                    break;
                }
                words_len += wsize; 
                nr_words++;
            }
            
            string line;
            if (j == size || nr_words == 1) {    // last line or lines with only one word              
                int line_size = 0;
                for (int k = i; k < i + nr_words; k++) {
                    line += words[k];
                    line_size += words[k].size();
                    if (line_size < L) {
                        line += ' ';
                        line_size++;
                    }
                }
                line += gen_space(L - line_size);                
            } else {  // normal lines
                int spaces = L - words_len;
                int nr_slacks = nr_words - 1;
                int regular_spaces = spaces / nr_slacks;
                int extra_spaces = spaces % nr_slacks;
                line = words[i];
                
                for (int k = i + 1; k < i + nr_words; k++) {
                    int cur_spaces = regular_spaces;
                    if (extra_spaces > 0) {
                        cur_spaces++;
                        extra_spaces--;
                    }
                    line += gen_space(cur_spaces);
                    line += words[k];
                }
            }
            
            i += nr_words;
            ret.push_back(line);
        }
        
        return ret;
    }
};