#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<deque<bool>> A(N, deque<bool>(N, true));
	for (int i = 0; i < N; ++i) {
		A[i][i] = false;
	}
	A[0][N - 1] = A[N - 1][0] = false;
	vector<int> B(N);
	vector<int> C{0};
	int u{};
	while (true) {
		int &v = B[u];
		while (v < N && !A[u][v]) {
			++v;
		}
		if (v == N) {
			break;
		}
		A[u][v] = A[v][u] = false;
		C.push_back(v);
		u = v;
	}
	C.push_back(0);
	for (int i = 0; i < C.size(); ++i) {
		cout << "a" << C[i] + 1 << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
