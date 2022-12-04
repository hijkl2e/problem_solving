#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int P{}, T{};
	cin >> P >> T;
	vector<vector<int>> A(P + 1);
	int a{}, b{};
	while (cin >> a >> b) {
		A[a].push_back(b);
	}
	for (auto &v : A) {
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
	}
	int ans{};
	for (int i = 1; i <= P; ++i) {
		if (A[i].size() == 1 && A[i][0] == -1) {
			continue;
		}
		for (int j = i + 1; j <= P; ++j) {
			if (A[i] == A[j]) {
				A[j] = {-1};
			}
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
