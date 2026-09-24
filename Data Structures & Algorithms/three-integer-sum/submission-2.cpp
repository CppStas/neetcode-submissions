class Solution {
struct TupleHash {
    std::size_t operator()(const std::tuple<int, int, int>& t) const {
        std::size_t h1 = std::hash<int>{}(std::get<0>(t));
        std::size_t h2 = std::hash<int>{}(std::get<1>(t));
        std::size_t h3 = std::hash<int>{}(std::get<2>(t));
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sz = nums.size();
        vector<vector<int>>  res;
        unordered_set<tuple<int,int,int>, TupleHash> c;

        vector<int> v(3, 0);
        for (int i{}; i <sz; ++i) {
            for (int j=i+1, k = sz-1; j <k && k > j; ) {
                if (-nums[i] == nums[j] + nums[k]) {
                    v[0] = nums[i];
                    v[1] = nums[j];
                    v[2] = nums[k];
                    sort(v.begin(),v.end());

                    auto t = make_tuple(v[0],v[1],v[2]);
                    if (!c.contains(t)) {
                        c.insert(t);
                        res.push_back(v);
                    }
                    --k;
                    ++j;
                } else if (-nums[i] < nums[j] + nums[k]) {
                    --k;
                } else if (-nums[i] > nums[j] + nums[k]) {
                    ++j;
                }
            }
        }
        return res;
    }
};
