#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = i + 1;
	}
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			B[j] ^= A[j];
		}
		A.erase(find(A.begin(), A.end(), B[i]));
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
