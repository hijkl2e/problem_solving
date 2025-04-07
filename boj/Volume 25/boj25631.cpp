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
	map<int, int> B;
	for (int i = 0; i < N; ++i) {
		++B[A[i]];
	}
	int ans{};
	for (auto &p : B) {
		ans = max(ans, p.second);
	}
	cout << ans << "\n";
	return 0;
}
