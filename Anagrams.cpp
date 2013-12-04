/**
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 */
 
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        unordered_map<string, vector<string> > str_buf;
        vector<string> ret;
        
        if (strs.size() == 0) {
            return ret;
        }
        
        // do some statistics
        for (int i = 0; i < strs.size(); i++) {
            string sorted = strs[i];
            
            sort(sorted.begin(), sorted.end());
            if (str_buf.count(sorted) > 0) {
                str_buf[sorted].push_back(strs[i]);
            } else {
                str_buf.emplace(sorted, vector<string>({strs[i]}));
            }
        }
        
        // push all anagrams into the output vector
        for (auto it = str_buf.begin(); it != str_buf.end(); ++it) {
            if (it->second.size() > 1) {
                for (int i = 0; i < it->second.size(); i++) {
                    ret.push_back(it->second[i]);
                }
            }
        }
        
        return ret;
    }
};