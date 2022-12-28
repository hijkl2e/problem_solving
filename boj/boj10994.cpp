#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A(4 * N - 3, string(4 * N - 3, ' '));
	for (int i = N - 1, k = 0; i >= 0; --i, k += 2) {
		for (int j = 0; j < 4 * i + 1; ++j) {
			A[k][k + j] = A[k + 4 * i][k + j] = '*';
			A[k + j][k] = A[k + j][k + 4 * i] = '*';
		}
	}
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}
