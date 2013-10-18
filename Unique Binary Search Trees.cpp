class Solution {
public:
	// Each child of the current root has nodes ranging from
	// i, n-1-i, repectively where i = 0,1,...,n-1, n = # of current
	// tree nodes. Recursively visit every block as the current root.
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n < 1)
            return 1;
        
        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += numTrees(i) * numTrees(n-1-i);
        }
    
        return sum;
    }
};