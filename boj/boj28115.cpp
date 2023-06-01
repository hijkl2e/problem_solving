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
	bool yes = true;
	for (int i = 1; i < N; ++i) {
		if (A[i] - A[i - 1] != A[1] - A[0]) {
			yes = false;
			break;
		}
	}
	if (yes) {
		cout << "YES\n";
		for (int i = 0; i < N; ++i) {
			cout << A[i] << (i == N - 1 ? "\n" : " ");
		}
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			cout << B[i] << (i == N - 1 ? "\n" : " ");
		}
	} else {
		cout << "NO\n";
	}
	return 0;
}
