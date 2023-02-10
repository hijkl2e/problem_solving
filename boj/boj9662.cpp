#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, K{};
	cin >> M >> K;
	vector<int> A(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i];
	}
	deque<bool> B(555);
	int now{};
	for (int i = 0; i < 22; ++i) {
		for (int x : A) {
			B[i] |= i - x >= 0 && !B[i - x];
		}
		now = 2 * now + B[i];
	}
	map<int, int> C;
	int x{}, y{};
	for (int i = 22;; ++i) {
		auto res = C.insert({now, i});
		if (!res.second) {
			x = res.first->second;
			y = i - x;
			break;
		}
		B.push_back(false);
		for (int x : A) {
			B[i] |= !B[i - x];
		}
		now = (2 * now + B[i]) & 0x3fffff;
	}
	int ans = accumulate(B.begin(), B.begin() + min(x, M + 1), 0);
	ans += max(M - x + 1, 0) / y * accumulate(B.begin() + x, B.begin() + x + y, 0);
	ans += accumulate(B.begin() + x, B.begin() + x + max(M - x + 1, 0) % y, 0);
	ans = M - ans;
	cout << ans << "\n";
	return 0;
}
