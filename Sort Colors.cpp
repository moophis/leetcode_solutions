/**
 * Given an array with n objects colored red, white or blue, 
 * sort them so that objects of the same color are adjacent, 
 * with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent 
 * the color red, white, and blue respectively.
 */

/*
 *  Invariant:
 *  ----------------------------------------
 *  |    0    |   1   |     ?     |    2   |
 *  ----------------------------------------
 *            ^       ^          ^
 *            p0      p1         p2
 */ 

class Solution {
public:
    void sortColors(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int p0 = 0, p1 = 0, p2 = n - 1;
        
        while (p1 <= p2) {
            switch (A[p1]) {
            case 0:
                swap(A[p0++], A[p1++]);
                break;
            case 1:
                p1++;
                break;
            case 2:
                swap(A[p1], A[p2--]);
                break;
            default:
                return;
            }
        }
    }
};