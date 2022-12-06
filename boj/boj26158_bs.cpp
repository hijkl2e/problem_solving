#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> D(N);
	for (int i = 0; i < N; ++i) {
		cin >> D[i];
	}
	vector<int> A(N);
	vector<int> B(N);
	int p{}, q{};
	for (int i = 0, j = 0; i < N; ++i) {
		if (p == q || A[q - 1] >= D[i]) {
			A[q] = D[i];
			++B[q++];
		} else {
			int idx = N - (lower_bound(A.rbegin() + N - q, A.rbegin() + N - p, D[i]) - A.rbegin());
			A[idx] = D[i];
			++B[idx];
		}
		if (++j == B[p] + K) {
			j -= B[p++];
		}
	}
	cout << q << "\n";
	return 0;
}
