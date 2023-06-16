#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, vector<int>> A;
	while (N--) {
		string i, j;
		int k{};
		cin >> i >> j >> k;
		auto &v = A[i];
		v.resize(3);
		int x = j == "left" ? 0 : j == "right" ? 1 : 2;
		v[x] = k;
	}
	int ans = 1;
	bool yes{};
	for (auto &p : A) {
		auto &v = p.second;
		if (count(v.begin(), v.end(), 0) < 2 || v[2] > 1) {
			yes = true;
		}
		ans += max({v[0], v[1], 1});
	}
	if (yes) {
		cout << ans << "\n";
	} else {
		cout << "impossible\n";
	}
	return 0;
}
