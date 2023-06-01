#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		B[A[i]] = i;
	}
	vector<int> C(N + 1);
	for (int i = 1; i <= N; ++i) {
		int x = B[i];
		int y = A[i];
		C[i] += x - i;
		C[y] += x - i;
		swap(A[i], A[x]);
		swap(B[i], B[y]);
	}
	for (int i = 1; i <= N; ++i) {
		cout << C[i] << (i == N ? "\n" : " ");
	}
	return 0;
}
