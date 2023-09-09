#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(6);
	for (int i = 1; i < 6; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> B(6);
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		B[x].push_back(y);
	}
	for (int i = 1; i < 6; ++i) {
		sort(B[i].begin(), B[i].end());
		B[i].resize(A[i]);
	}
	int ans = 240;
	for (int i = 1; i < 6; ++i) {
		ans += accumulate(B[i].begin() + 1, B[i].end(), 0) + B[i].back();
	}
	cout << ans << "\n";
	return 0;
}
