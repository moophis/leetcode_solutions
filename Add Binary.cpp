/*
 * Given two binary strings, return their sum (also a binary string).

   For example,
   a = "11"
   b = "1"
   Return "100".
 */
class Solution {
public:
    string addBinary(string a, string b) {
        size_t alen = a.length();
        size_t blen = b.length();
        char carry = 0;
        size_t pos = s.size() - 1;

        string s(max(alen, blen), '0');
        
        for (int i = alen - 1, j = blen - 1; i >= 0 || j >= 0; i--, j--) {
            char t = carry;
            if (i >= 0) {
                t += a[i] - '0';
            }
            if (j >= 0) {
                t += b[j] - '0';
            }
            carry = t >> 1;
            s[pos--] = (t % 2) + '0';
        }

        if (carry == 1)
            s = s.insert(0, "1");
        
        return s;
    }
};