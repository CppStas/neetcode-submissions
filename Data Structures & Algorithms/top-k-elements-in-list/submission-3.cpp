class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m1;

        for (auto n : nums) {
            ++m1[n];
        }

        sort(nums.begin(), nums.end(),[&](auto lhs, auto rhs) {
            auto a = m1[lhs];
            auto b =  m1[rhs];
			if (a != b)
                return a > b;
			return lhs < rhs;
        });

        vector<int> ans;
        auto it = nums.begin();
        while (k-- > 0) {
            ans.push_back(*it);
            it = it + m1[*it];
        }
        return ans;
    }
};
