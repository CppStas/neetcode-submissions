class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        if (sz == 1) return 1;
        unordered_set<int> s(nums.begin(), nums.end());

        int res{};
        for (int i{0}; i < sz; ++i) {
            const int v = nums[i];
            if (s.contains(v-1)) continue;
            int l = v;
            while(s.contains(l + 1)) {
                ++l;
            }
            res = max(res, l - v + 1);

        }
        return res;
    }
};
