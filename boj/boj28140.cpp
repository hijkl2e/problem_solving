#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> A, B;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'R') {
			A.push_back(i);
		} else if (S[i] == 'B') {
			B.push_back(i);
		}
	}
	A.push_back(INF);
	A.push_back(INF);
	B.push_back(INF);
	B.push_back(INF);
	vector<ii> C(N);
	vector<ii> D(N);
	for (int k = 0; k < 2; ++k) {
		auto &v1 = k ? B : A;
		auto &v2 = k ? D : C;
		for (int i = 0, j = 0; i < N; ++i) {
			if (i > v1[j]) {
				++j;
			}
			v2[i] = {v1[j], v1[j + 1]};
		}
	}
	ostringstream oss;
	while (Q--) {
		int l{}, r{};
		cin >> l >> r;
		int p = C[l].second;
		if (p == INF || D[p].second > r) {
			oss << "-1\n";
		} else {
			oss << C[l].first << " " << C[l].second << " ";
			oss << D[p].first << " " << D[p].second << "\n";
		}
	}
	cout << oss.str();
	return 0;
}
