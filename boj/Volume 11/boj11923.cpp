#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, C{};
	cin >> N >> C;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		int sum{}, cnt{};
		for (int j = i; j < N; ++j) {
			if (sum + A[j] <= C) {
				sum += A[j];
				++cnt;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
