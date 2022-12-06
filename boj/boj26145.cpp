#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + M);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N + M; ++j) {
			int x{};
			cin >> x;
			A[i] -= x;
			A[j] += x;
		}
	}
	for (int i = 0; i < N + M; ++i) {
		cout << A[i] << (i == N + M - 1 ? "\n" : " ");
	}
	return 0;
}
