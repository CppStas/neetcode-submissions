class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        if (sz == 1) return 1;
        unordered_set<int> s(nums.begin(), nums.end());

        int res{1};
        for (int vv : nums) {
            int v = vv;
            if (s.contains(v-1)) continue;
            while(s.contains(++v));
            res = max(res, v - vv);
        }
        return res;
    }
};
