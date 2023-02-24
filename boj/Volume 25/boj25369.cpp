#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A;

bool solve(int n, int s, int x) {
	if (n == N) {
		return x > M;
	}
	for (int i = s; i < 10; ++i) {
		A.push_back(i);
		if (solve(n + 1, i, x * i)) {
			return true;
		}
		A.pop_back();
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	M = 1;
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		M *= x;
	}
	if (solve(0, 1, 1)) {
		for (int i = 0; i < N; ++i) {
			cout << A[i] << (i == N - 1 ? "\n" : " ");
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
