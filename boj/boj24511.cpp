#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int> C;
	for (int i = N - 1; i >= 0; --i) {
		if (A[i] == 0) {
			C.push_back(B[i]);
		}
	}
	int M{};
	cin >> M;
	while (C.size() < M) {
		int x{};
		cin >> x;
		C.push_back(x);
	}
	for (int i = 0; i < M; ++i) {
		cout << C[i] << (i == M - 1 ? "\n" : " ");
	}
	return 0;
}
