#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> fibo(34);
	fibo[1] = 1;
	for (int i = 2; i < fibo.size(); ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	vector<int> A(3e6 + 1);
	deque<bool> B(16);
	for (int i = 1; i < A.size(); ++i) {
		fill(B.begin(), B.end(), false);
		for (int j = 1; i - fibo[j] >= 0; ++j) {
			B[A[i - fibo[j]]] = true;
		}
		for (int j = 0; B[j]; ++j) {
			A[i] = j + 1;
		}
	}
	int N{};
	cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}
	int x{};
	for (int i = 0; i < N; ++i) {
		x ^= A[P[i]];
	}
	cout << (x ? "koosaga" : "cubelover") << "\n";
	return 0;
}
