// https://oj.leetcode.com/problems/implement-strstr/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == nullptr || needle == nullptr) {
            return nullptr;
        }
        if (!*needle) {
            return haystack;
        }
        
        char *needle_begin = needle;
        char *first_match = "";
        
        while (*haystack && *needle) {
            if (*haystack == *needle) {
                if (!*first_match) {
                    first_match = haystack;
                }
                haystack++;
                needle++;
            } else {
                needle = needle_begin;
                if (*first_match) {
                    haystack = first_match + 1;  
                    first_match = "";
                } else {
                    haystack++;
                }
            }
        }
        
        return *needle ? nullptr : first_match;
    }
};