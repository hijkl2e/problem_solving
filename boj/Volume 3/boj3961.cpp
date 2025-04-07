#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> key{
		"qwertyuiop", "asdfghjkl", "zxcvbnm"
	};
	map<char, int> k2x, k2y;
	for (int i = 0; i < key.size(); ++i) {
		for (int j = 0; j < key[i].size(); ++j) {
			k2x[key[i][j]] = i;
			k2y[key[i][j]] = j;
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		string S;
		int L{};
		cin >> S >> L;
		vector<is> A(L);
		for (int i = 0; i < L; ++i) {
			auto &E = A[i].second;
			cin >> E;
			for (int j = 0; j < S.size(); ++j) {
				A[i].first += abs(k2x[S[j]] - k2x[E[j]]) + abs(k2y[S[j]] - k2y[E[j]]);
			}
		}
		sort(A.begin(), A.end());
		for (auto &p : A) {
			cout << p.second << " " << p.first << "\n";
		}
	}
	return 0;
}
