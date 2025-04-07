#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int K{};
	cin >> K;
	if (K == 2) {
		for (int i = 0; i < N; ++i) {
			reverse(A[i].begin(), A[i].end());
		}
	} else if (K == 3) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N / 2; ++j) {
				swap(A[j][i], A[N - j - 1][i]);
			}
		}
	}
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}
