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
	vector<int> B(1000001);
	deque<bool> C(1000001);
	for (int i = 0; i < N; ++i) {
		C[A[i]] = true;
	}
	for (int i = 1; i < C.size(); ++i) {
		if (!C[i]) {
			continue;
		}
		for (int j = 2 * i; j < C.size(); j += i) {
			if (C[j]) {
				++B[i], --B[j];
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << B[A[i]] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
