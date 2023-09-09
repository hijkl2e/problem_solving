#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<string> B(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, B[i]);
	}
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2 * M; ++j) {
			yes &= B[i][j] == A[i][j / 2];
		}
	}
	cout << (yes ? "" : "Not ") << "Eyfa\n";
	return 0;
}
