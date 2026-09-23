class Solution {
public:
	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		int sz = static_cast<int>(position.size());
		if (sz == 1) return 1;

		map<int, int, greater<int>> m;

		for (int i{}; i < sz; ++i) {
			m[position[i]] = speed[i];
		}
		
		auto cur = m.begin();
        int r = 1;
        auto pd = (target - cur->first) / static_cast<float>(cur->second);
        ++cur;
		for (; cur != m.end(); ++cur) {
			auto d = (target - cur->first) / static_cast<float>(cur->second);
			if (d > pd) {
				++r;
                pd = d;
			}
		}
		
		return r;
	}
};