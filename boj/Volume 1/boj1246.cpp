#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	sort(A.rbegin(), A.rend());
	if (N < M) {
		A.resize(N);
		M = N;
	}
	int p{};
	for (int i = 0; i < M; ++i) {
		if ((p + 1) * A[p] <= (i + 1) * A[i]) {
			p = i;
		}
	}
	cout << A[p] << " " << (p + 1) * A[p] << "\n";
	return 0;
}
