#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

vector<int> solve(vector<int> &A) {
	vector<int> B(100001, INF);
	B[0] = 0;
	for (int i = 0; i < A.size(); ++i) {
		for (int j = B.size() - 1; j >= A[i]; --j) {
			B[j] = min(B[j], B[j - A[i]] + 1);
		}
	}
	return B;
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
	int M{};
	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	vector<int> C = solve(A);
	vector<int> D = solve(B);
	int ans = INF;
	for (int i = 1; i < C.size(); ++i) {
		ans = min(ans, C[i] + D[i]);
	}
	if (ans == INF) {
		cout << "impossible\n";
	} else {
		cout << ans << "\n";
	}
	return 0;
}
