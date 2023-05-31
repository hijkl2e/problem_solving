#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<vector<int>> A, B;

bool solve() {
	vector<int> C(3);
	vector<int> D(3);
	int p1 = 0, p2 = 1;
	while (true) {
		if (p1 > p2) {
			swap(p1, p2);
		}
		if (p1 == 0 && C[0] == N) {
			return false;
		}
		int res = A[B[p1][C[p1]++]][B[p2][C[p2]++]];
		if (res == 2) {
			swap(p1, p2);
		}
		if (++D[p2] == K) {
			return p2 == 0;
		}
		p1 ^= p2 ^ 3;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	A.assign(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> A[i][j];
		}
	}
	B.resize(3);
	for (int i = 1; i < 3; ++i) {
		B[i].resize(20);
		for (int j = 0; j < 20; ++j) {
			cin >> B[i][j];
		}
	}
	B[0].resize(N);
	for (int i = 0; i < N; ++i) {
		B[0][i] = i + 1;
	}
	bool yes{};
	do {
		if (solve()) {
			yes = true;
			break;
		}
	} while (next_permutation(B[0].begin(), B[0].end()));
	cout << yes << "\n";
	return 0;
}
