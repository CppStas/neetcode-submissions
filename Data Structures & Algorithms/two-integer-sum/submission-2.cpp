class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const size_t sz = nums.size();
        std::unordered_map<int,int> m;
        for (int i{};i<sz;++i) {
            m[nums[i]]=i;
        }
        for (int i{};i<sz;++i) {
            const int second = target - nums[i];
            const int idx = m[second];
            if (idx > 0 && i != idx) {
                    return i < idx ? std::vector<int>{i, idx} : std::vector<int>{idx, i};
                }
        }
        return {0,1};
    }
};
