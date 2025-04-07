#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<set<ll>> A(51);
	vector<set<ll>> B(51);
	for (int i = 0; i < N; ++i) {
		string s;
		getline(cin, s);
		A[s.size()].insert(stoll(s, nullptr, 2));
	}
	for (int i = 0; i < N; ++i) {
		string s;
		getline(cin, s);
		B[s.size()].insert(stoll(s, nullptr, 2));
	}
	int M{};
	cin >> M;
	cin.ignore();
	while (M--) {
		string S;
		getline(cin, S);
		int C{};
		for (int i = 0; i < S.size(); ++i) {
			ll x{};
			for (int j = 0; i + j < S.size() && j < 50; ++j) {
				x = 2 * x + S[i + j] - '0';
				C -= A[j + 1].count(x);
				C += B[j + 1].count(x);
			}
		}
		if (C > 0) {
			cout << "LOW " << C << "\n";
		} else if (C < 0) {
			cout << "HIGH " << -C << "\n";
		} else {
			cout << "GOOD\n";
		}
	}
	return 0;
}
