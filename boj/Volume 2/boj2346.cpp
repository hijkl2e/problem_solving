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
		B[i] = i;
	}
	vector<int> C(N);
	for (int i = 0, p = 0, sz = N - 1; i < N; ++i, --sz) {
		C[i] = B[p];
		B.erase(B.begin() + p);
		if (i == N - 1) {
			break;
		}
		p += A[C[i]] - (A[C[i]] > 0);
		p = (p % sz + sz) % sz;
	}
	for (int i = 0; i < N; ++i) {
		cout << C[i] + 1 << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
