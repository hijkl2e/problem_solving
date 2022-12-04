#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(M + 1);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	A[M] = N + 1;
	deque<bool> chk(N + 1);
	for (int i = 0; i < M; ++i) {
		chk[A[i]] = true;
	}
	for (int i = 0, j = 1; i <= M; ++i) {
		while (j < A[i]) {
			if (!chk[j]) {
				cout << j << "\n";
			}
			++j;
		}
		if (i < M) {
			cout << A[i] << "\n";
		}
	}
	return 0;
}
