#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	ii ans{-1, 1e9};
	for (int i = 1; i <= N - 2; ++i) {
		int maxv = max(A[i], A[i + 2]);
		if (ans.second > maxv) {
			ans = {i, maxv};
		}
	}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
