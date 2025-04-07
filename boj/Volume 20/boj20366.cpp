#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<iii> B;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			B.push_back({A[i] + A[j], i, j});
		}
	}
	sort(B.begin(), B.end());
	int ans = 2e9;
	for (int i = 0; i < B.size(); ++i) {
		auto &[w1, u1, v1] = B[i];
		for (int j = i + 1; j < B.size(); ++j) {
			auto &[w2, u2, v2] = B[j];
			if (u1 != u2 && u1 != v2 && v1 != u2 && v1 != v2) {
				ans = min(ans, w2 - w1);
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
