#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		A[i] = i;
	}
	int M{};
	cin >> M;
	while (M--) {
		int x{}, y{};
		cin >> x >> y;
		A[x] = max(A[x], y);
	}
	int ans{};
	for (int i = 1, k = 1; i <= N; ++i) {
		k = max(k, A[i]);
		if (k == i) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
