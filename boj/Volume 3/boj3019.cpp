#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A[8]{
		{}, {{}, {0, 0, 0}}, {{0}},
		{{0, 1}, {-1}}, {{-1, -1}, {1}},
		{{0, 0}, {1}, {-1, 0}, {-1}},
		{{0, 0}, {0}, {1, 1}, {-2}},
		{{0, 0}, {0}, {0, -1}, {2}}
	};
	int C{}, P{};
	cin >> C >> P;
	vector<int> H(C);
	for (int i = 0; i < C; ++i) {
		cin >> H[i];
	}
	int ans{};
	for (auto &v : A[P]) {
		for (int i = 0; i + v.size() < C; ++i) {
			bool yes = true;
			for (int j = 0; j < v.size(); ++j) {
				if (H[i + j + 1] != H[i] + v[j]) {
					yes = false;
					break;
				}
			}
			if (yes) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
