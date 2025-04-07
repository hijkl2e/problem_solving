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
		B[i] = A[i] == 300 ? 1 : A[i] >= 275 ? 2 : A[i] >= 250 ? 3 : 4;
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
