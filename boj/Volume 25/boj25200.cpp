#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> U(M);
	vector<int> V(M);
	for (int i = 0; i < M; ++i) {
		cin >> U[i] >> V[i];
	}
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		A[i] = i;
	}
	for (int i = M - 1; i >= 0; --i) {
		A[U[i]] = A[V[i]];
	}
	for (int i = 1; i <= N; ++i) {
		cout << A[i] << (i == N ? "\n" : " ");
	}
	return 0;
}
