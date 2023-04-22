#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(2 * N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int k = 1; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			cin >> A[N + i];
		}
		sort(A.rbegin(), A.rend());
	}
	cout << A[N - 1] << "\n";
	return 0;
}
