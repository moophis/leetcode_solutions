class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int hi, lo, len = 1, base = 10;
        bool sign = false;
        
        if (x < 0) {
            sign = true;
            x = - x;
        }
        
        while (x != 0 && x % 10 == 0)
            x = x / 10;
            
        while (x / base != 0) {
            len++;
            base = base * 10;
        }
        
        for (hi = len, lo = 1; hi > lo; hi--, lo++) {
            int base_hi = 1, base_lo = 1;
            int h, l;
            for (int i = 1; i < hi; i++) 
                base_hi = base_hi * 10;
            for (int i = 1; i < lo; i++)
                base_lo = base_lo * 10;
            h = (x / base_hi) % 10;
            l = (x / base_lo) % 10;
            x = x - h * base_hi + l * base_hi - l * base_lo + h * base_lo;
        }
        
        return sign ? -x : x;
    }
};