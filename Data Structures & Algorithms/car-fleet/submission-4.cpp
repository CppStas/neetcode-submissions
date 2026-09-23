class Solution {
public:
	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		int sz = static_cast<int>(position.size());
		if (sz == 1) return 1;

		map<int, int, greater<int>> m;

		for (int i{}; i < sz; ++i) {
			m[position[i]] = speed[i];
		}
		
		auto prev = m.begin();
        int r = 1;
		auto [pp, ps] = *prev;
        auto pd = (target - pp) / static_cast<float>(ps);

		for (auto cur = next(prev); cur != m.end(); ++cur) {
			auto [p, s] = *cur;
			auto d = (target - p) / static_cast<float>(s);

			if (d > pd) {
				++r;
                pd = d;
			}
		}
		
		return r;
	}
};