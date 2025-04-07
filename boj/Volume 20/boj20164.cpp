#include <bits/stdc++.h>

using namespace std;

int minv, maxv;

int cnt_odd(int N) {
	int cnt{};
	while (N) {
		if (N % 2) {
			++cnt;
		}
		N /= 10;
	}
	return cnt;
}

void solve(int N, int cnt) {
	cnt += cnt_odd(N);
	if (N < 10) {
		minv = min(minv, cnt);
		maxv = max(maxv, cnt);
		return;
	} else if (N < 100) {
		solve(N / 10 + N % 10, cnt);
		return;
	}
	string S = to_string(N);
	for (int i = 1; i < S.size(); ++i) {
		for (int j = i + 1; j < S.size(); ++j) {
			solve(stoi(S.substr(0, i)) + stoi(S.substr(i, j - i)) + stoi(S.substr(j)), cnt);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	minv = 1e9;
	solve(N, 0);
	cout << minv << " " << maxv << "\n";
	return 0;
}
