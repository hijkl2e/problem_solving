#include <bits/stdc++.h>

using namespace std;

map<int, int> dp;

int solve(int x) {
	auto res = dp.insert({x, 0});
	int &ret = res.first->second;
	if (!res.second) {
		return ret;
	}
	deque<bool> vst(31);
	for (int i = 32 - __builtin_clz(x); i > 0; --i) {
		int y = (x >> i) | (x & ((1 << (i - 1)) - 1));
		vst[solve(y)] = true;
	}
	for (int i = 0; vst[i]; ++i) {
		ret = i + 1;
	}
	return ret;
}

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
		int x = A[i];
		for (int j = 2; j * j <= x; ++j) {
			int cnt{};
			while (x % j == 0) {
				x /= j;
				++cnt;
			}
			if (cnt) {
				B[j] |= 1 << (cnt - 1);
			}
		}
		if (x > 1) {
			B[x] |= 1;
		}
	}
	dp[0] = 0;
	int ans{};
	for (auto &p : B) {
		ans ^= solve(p.second);
	}
	cout << (ans ? "koosaga" : "cubelover") << "\n";
	return 0;
}
