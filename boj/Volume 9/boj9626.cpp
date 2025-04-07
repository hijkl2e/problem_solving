#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, N{};
	cin >> M >> N;
	int U{}, L{}, R{}, D{};
	cin >> U >> L >> R >> D;
	cin.ignore();
	vector<string> A(M);
	for (int i = 0; i < M; ++i) {
		getline(cin, A[i]);
	}
	vector<string> B(M + U + D, string(N + L + R, '#'));
	for (int i = 0; i < B.size(); ++i) {
		for (int j = 0; j < B[i].size(); ++j) {
			if ((i + j) % 2) {
				B[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			B[U + i][L + j] = A[i][j];
		}
	}
	for (auto &s : B) {
		cout << s << "\n";
	}
	return 0;
}
