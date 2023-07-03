#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<string>> A(N, vector<string>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<string> B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			bool yes{};
			for (int k = 1; k < 3; ++k) {
				if (i + k < N && A[i][j] == A[i + k][j]) {
					yes = true;
					break;
				}
				if (j + k < M && A[i][j] == A[i][j + k]) {
					yes = true;
					break;
				}
			}
			if (yes) {
				B.push_back(A[i][j]);
			}
		}
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	if (B.size()) {
		for (auto &s : B) {
			cout << s << "\n";
		}
	} else {
		cout << "MANIPULATED\n";
	}
	return 0;
}
