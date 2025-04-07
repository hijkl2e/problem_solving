#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		cin >> A[i];
	}
	vector<int> B;
	int cnt = 1;
	for (int i = 0; i < N - 1; ++i) {
		if (A[i] > K) {
			B.push_back(cnt);
			cnt = 1;
		} else {
			++cnt;
		}
	}
	B.push_back(cnt);
	int ans = B[0];
	for (int i = 1; i < B.size(); ++i) {
		ans = max(ans, B[i - 1] + B[i]);
	}
	cout << ans << "\n";
	return 0;
}
