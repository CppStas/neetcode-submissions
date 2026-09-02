class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        if (sz == 1) return 1;
        unordered_set<int> s(nums.begin(), nums.end());

        int res{1};
        for (int i{}; i < sz; ++i) {
            int v = nums[i];
            if (!s.contains(v-1)) {
                while(s.contains(++v));
                res = max(res, v - nums[i]);
            }
        }
        return res;
    }
};
