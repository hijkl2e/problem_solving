#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> D(N, -1);
	int x{};
	D[x] = 0;
	while (D[A[x]] == -1) {
		D[A[x]] = D[x] + 1;
		x = A[x];
	}
	cout << D[K] << "\n";
	return 0;
}
