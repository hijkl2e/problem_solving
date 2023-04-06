#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<vector<int>> A(N);
		for (int i = 0; i < N; ++i) {
			int K{};
			cin >> K;
			while (K--) {
				int x{};
				cin >> x;
				if (A[i].empty() || A[i].back() < x) {
					A[i].push_back(x);
				}
			}
		}
		sort(A.begin(), A.end(), [](vector<int> &v1, vector<int> &v2) {
			return v1.back() < v2.back();
		});
		map<int, int> dp;
		dp[0] = 0;
		for (auto &v : A) {
			auto it1 = dp.insert({v.back(), 0}).first;
			for (int i = 0; i < v.size(); ++i) {
				it1->second = max<int>(it1->second, (--dp.lower_bound(v[i]))->second + v.size() - i);
			}
			auto it2 = next(it1);
			while (it2 != dp.end() && it1->second >= it2->second) {
				it2 = dp.erase(it2);
			}
		}
		int ans = (--dp.end())->second;
		cout << ans << "\n";
	}
	return 0;
}
