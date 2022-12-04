#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(2 * N);
	for (int i = 0; i < N; ++i) {
		cin >> A[2 * i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> A[2 * i + 1];
	}
	int cnt1{}, cnt2{}, ans{};
	deque<bool> B(N + 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (B[A[2 * i + j]]) {
				--cnt1; ++cnt2;
			} else {
				++cnt1;
			}
			B[A[2 * i + j]] ^= true;
		}
		if (cnt1 == 0 && cnt2 >= K) {
			++ans;
			cnt2 = 0;
		}
	}
	cout << ans << "\n";
	return 0;
}
