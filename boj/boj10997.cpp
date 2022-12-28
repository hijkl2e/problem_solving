#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	if (N == 1) {
		cout << "*\n";
		return 0;
	}
	vector<string> A(4 * N - 1, string(4 * N - 3, ' '));
	for (int i = 4 * (N - 1), k = 0; i >= 0; i -= 4, k += 2) {
		for (int j = 0; j < i + 1; ++j) {
			A[k][k + j] = A[k + i + 2][k + j] = '*';
			A[k + j + 1][k] = A[k + j + 1][k + i] = '*';
		}
		A[k + 1][k + i] = i ? ' ' : '*';
		A[k + 2][k + i - 1] = i ? '*' : ' ';
	}
	for (int i = 0; i < A.size(); ++i) {
		cout << (i == 1 ? "*" : A[i]) << "\n";
	}
	return 0;
}
