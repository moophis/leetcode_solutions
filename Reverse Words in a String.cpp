// http://oj.leetcode.com/submissions/detail/5069805/

class Solution {
public:
    void reverseWords(string &s) {
        if (s == "") {
            return;
        }
        
        int len = s.size();
        string reversed = "";
        list<string> li;
        
        for (int i = 0; i < len; ) {
            while (i < len && s[i] == ' ')
                i++;
            if (i == len)
                break;
                
            int start = i;
            while (i < len && s[i] != ' ')
                i++;
            li.push_back(s.substr(start, i - start));
        }
        
        s.clear();
        while (!li.empty()) {
            s += li.back();
            li.pop_back();
            if (!li.empty())
                s += " ";
        }
    }
};