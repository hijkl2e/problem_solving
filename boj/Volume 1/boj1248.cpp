#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<char>> A;
vector<int> B;

bool check(int n) {
	int sum{};
	for (int i = n; i >= 0; --i) {
		sum += B[i];
		if ((A[i][n] == '+' && sum <= 0) || (A[i][n] == '-' && sum >= 0) || (A[i][n] == '0' && sum != 0)) {
			return false;
		}
	}
	return true;
}

bool solve(int n) {
	if (n == N) {
		return true;
	}
	for (int i = -10; i < 11; ++i) {
		B[n] = i;
		if (check(n) && solve(n + 1)) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.assign(N, vector<char>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	B.resize(N);
	solve(0);
	for (int i = 0; i < N; ++i) {
		cout << B[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
