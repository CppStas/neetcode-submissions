class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> c;

        auto it = nums.begin();
        while (it != nums.end()) {
            if (c.count(*it)) return true;
            c.insert(*it);
            ++it;
        }
        return false;
    }
};