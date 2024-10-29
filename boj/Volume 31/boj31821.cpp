#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int M{};
	cin >> M;
	int ans{};
	while (M--) {
		int x{};
		cin >> x;
		ans += A[x];
	}
	cout << ans << "\n";
	return 0;
}
