#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int N;
vector<int> A, C, D, E, F;
vector<vector<int>> B;
int ans;

void solve(int x, int y) {
	if (A[0] <= D[0] && A[1] <= D[1] && A[2] <= D[2] && A[3] <= D[3]) {
		if (ans > y) {
			ans = y;
			F = E;
		}
		return;
	}
	for (int i = x; i < N; ++i) {
		for (int j = 0; j < 4; ++j) {
			D[j] += B[i][j];
		}
		E.push_back(i);
		solve(i + 1, y + C[i]);
		for (int j = 0; j < 4; ++j) {
			D[j] -= B[i][j];
		}
		E.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(4);
	for (int i = 0; i < 4; ++i) {
		cin >> A[i];
	}
	B.assign(N, vector<int>(4));
	C.resize(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> B[i][j];
		}
		cin >> C[i];
	}
	D.resize(4);
	ans = INF;
	solve(0, 0);
	if (ans == INF) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
		for (int i = 0; i < F.size(); ++i) {
			cout << F[i] + 1 << (i == F.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
