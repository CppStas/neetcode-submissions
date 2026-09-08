class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sz = numbers.size();
        if (sz == 0) return {1,2};
        int l = 0;
        int r = sz - 1;
        
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                return {l+1, r+1};
            } else if (sum > target) {
                --r;
            } else {
                ++l;
            }
        }


        return {};
    }
};
