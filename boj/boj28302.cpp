#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, char, char>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	string S, T;
	cin >> N >> S >> M >> T;
	vector<rec> A, B;
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < S.size() - 1; ++i) {
			while (i < S.size() - 1 && S[i] != S[i + 1]) {
				A.push_back({1, i + 1, S[i], S[i + 1]});
				S[i] = 'R' + 'G' + 'B' - S[i] - S[i + 1];
				S.erase(S.begin() + i + 1);
				i = max(i - 1, 0);
			}
		}
		char c1 = S[0] == 'R' ? 'G' : S[0] == 'G' ? 'B' : 'R';
		char c2 = S[0] == 'R' ? 'B' : S[0] == 'G' ? 'R' : 'G';
		while (S.size() > 2) {
			A.push_back({2, 1, c1, c2});
			A.push_back({1, 2, c2, S[0]});
			A.push_back({1, 2, c1, S[0]});
			A.push_back({1, 1, c1, c2});
			S.resize(S.size() - 2);
		}
		if (S.size() == 2 && S[0] != 'R') {
			A.push_back({2, 1, 'R', 'G' + 'B' - S[0]});
			A.push_back({1, 2, 'G' + 'B' - S[0], S[0]});
			S = "RR";
		}
		swap(S, T);
		swap(A, B);
	}
	if (S == T) {
		for (auto &[q, a, x, y] : B) {
			q ^= 3;
		}
		copy(B.rbegin(), B.rend(), back_inserter(A));
		cout << A.size() << "\n";
		for (auto &[q, a, x, y] : A) {
			if (q == 1) {
				cout << "1 " << a << " " << a + 1 << "\n";
			} else {
				cout << "2 " << a << " " << x << " " << y << "\n";
			}
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
