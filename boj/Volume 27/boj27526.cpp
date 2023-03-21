#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A, B;
deque<bool> C;

void solve(int x) {
	if (x == N * M) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				int y = B[A[i * M + (i % 2 ? M - j - 1 : j)]];
				if (y == N * M) {
					cout << "#";
				} else {
					cout << y;
				}
			}
			cout << "\n";
		}
		return;
	}
	for (int i = C[x] ? 0 : x; 0 <= i && i <= x; i += C[x] ? 1 : -1) {
		A.insert(A.begin() + i, x);
		solve(x + 1);
		A.erase(A.begin() + i);
	}
	C[x] ^= true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	B.resize(N * M);
	for (int i = 0; i < N * M; ++i) {
		B[i] = i + 1;
	}
	for (int i = 1; i < N; i += 2) {
		reverse(B.begin() + i * M, B.begin() + (i + 1) * M);
	}
	C.resize(N * M);
	solve(0);
	return 0;
}
