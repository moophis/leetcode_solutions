// https://oj.leetcode.com/problems/4sum/

// O(n^3) will not be acceptable.
// Use hash map to pair sum of two numbers with that
// of other two.

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
	    vector<vector<int> > ret;
	    if (num.size() < 4) {
	        return ret;
	    }
	    
	    sort(num.begin(), num.end());
	    
	    vector<pair<int, int> > pairs;
	    size_t size = num.size();
	    
	    for (size_t i = 0; i < size; i++) {
	        for (size_t j = i+1; j < size; j++) {
	            pairs.push_back(make_pair(i, j));
	        }
	    }
	    
	    unordered_multimap<int, pair<int, int> > mhp;
	    unordered_set<string> sset; // "index1_index2_index3_index4"
	    for (auto it = pairs.begin(); it != pairs.end(); ++it) {
	        int i = it->first;
	        int j = it->second;
	        int sum = num[i] + num[j];
	        int cur = target - sum;
	        // cout << "num[" << i << "]=" << num[i] << " num[" << j << "]="
	        // << num[j] << " (sum=" << sum << "). Need " << cur << endl;
	        
	        if (mhp.count(cur) > 0) {
	            for (auto vit = mhp.find(cur); vit != mhp.end() && vit->first == cur; ++vit) {
	                pair<int, int> p = vit->second;
	                if (p.first == i || p.first == j || p.second == i || p.second == j) {
	                    continue;
	                }
	                // cout << "\tFind (cur=" << vit->first << "): c = " << num[p.first] << " d = " << num[p.second] << endl;
	                stringstream ss;
	                int ans[4] = {num[p.first], num[p.second], num[i], num[j]};
	                sort(ans, ans + 4);
	                ss << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3];
	                string s = ss.str();
	                
	                if (sset.count(s) == 0) {
	                    sset.emplace(s);
	                    ret.push_back({ans[0], ans[1], ans[2], ans[3]});
	                } else {
	                    // cout << "\tFind duplicate" << endl;
	                }
	            }
	        }
	        mhp.emplace(sum, make_pair(i, j));
	    }
	    
	    return ret;
	}
}; 