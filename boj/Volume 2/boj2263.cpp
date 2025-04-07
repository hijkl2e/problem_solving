#include <bits/stdc++.h>

using namespace std;

vector<int> A, B, C, D;

void solve(int x1, int x2, int y1, int y2) {
	if (x1 == x2) {
		return;
	}
	D.push_back(B[y2 - 1]);
	int z = C[B[y2 - 1]];
	solve(x1, z, y1, y1 - x1 + z);
	solve(z + 1, x2, y1 - x1 + z, y2 - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	C.resize(N + 1);
	for (int i = 0; i < N; ++i) {
		C[A[i]] = i;
	}
	solve(0, N, 0, N);
	for (int i = 0; i < N; ++i) {
		cout << D[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
