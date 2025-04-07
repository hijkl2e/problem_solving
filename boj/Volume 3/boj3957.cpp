#include <bits/stdc++.h>

using namespace std;

using ss = pair<string, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int N{};
		cin >> N;
		cin.ignore();
		vector<vector<string>> A(N);
		vector<vector<string>> B(N);
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			int M{};
			cin >> M;
			A[i].resize(M);
			for (int j = 0; j < M; ++j) {
				cin >> A[i][j];
			}
			cin >> M;
			B[i].resize(M);
			for (int j = 0; j < M; ++j) {
				cin >> B[i][j];
			}
			sort(A[i].begin(), A[i].end());
			sort(B[i].begin(), B[i].end());
		}
		vector<ss> C;
		for (int i = 0; i < N; ++i) {
			for (auto &s1 : A[i]) {
				for (auto &s2 : B[i]) {
					C.push_back({s1, s2});
				}
			}
		}
		sort(C.begin(), C.end());
		C.resize(unique(C.begin(), C.end()) - C.begin());
		if (tc) {
			cout << "\n";
		}
		for (auto &p : C) {
			bool yes = true;
			for (int i = 0; i < N; ++i) {
				if (binary_search(A[i].begin(), A[i].end(), p.first)
						^ binary_search(B[i].begin(), B[i].end(), p.second)) {
					yes = false;
					break;
				}
			}
			if (yes) {
				cout << "(" << p.first << ", " << p.second << ")\n";
			}
		}
	}
	return 0;
}
