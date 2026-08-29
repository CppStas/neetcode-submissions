class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; 
        for(int i = 0; i < nums.size(); i++) {
            const int val = nums[i];
            const int y = target - val;
            if(m.contains(y)) {
                return {m[y], i}; 
            }
            m[val] = i; 
        }
        return {};
    }
};
