#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(5 * N + 1);
	for (int i = 0; i < A.size(); ++i) {
		getline(cin, A[i]);
	}
	vector<int> B(5);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int p = 4;
			while (p > 0 && A[5 * i + p][5 * j + 1] == '.') {
				--p;
			}
			++B[p];
		}
	}
	for (int i = 0; i < 5; ++i) {
		cout << B[i] << (i == 4 ? "\n" : " ");
	}
	return 0;
}
