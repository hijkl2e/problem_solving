#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int cnt{};
	for (int x : A) {
		if (cnt == x - 1) {
			++cnt;
		}
	}
	int ans = N - cnt;
	cout << ans << "\n";
	return 0;
}
